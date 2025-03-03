#!/usr/bin/env bash

ARGS="Wrong number of arguments"
FATAL="Fatal error"
err=0
port=8080

check()
{
[ $? -eq 1 ] && echo -e "✅\c" || { echo -e "❌\c"; err=$(( $err + 1 )); }
[ "$(cat log.txt)" = "$1" ] && echo -e "\033[70G✅" || { echo -e "\033[70G❌"; err=$(( $err + 1 )); }
}


check_diff()
{
INDENT=50

case "$1" in
	5 | 7)
		INDENT=55
		;;
esac

diff "log$1.txt" "assets/test$1" &> /dev/null
[ $? -eq 0 ] &&	echo -e "\033[${INDENT}G✅\c" || { echo -e "\033[${INDENT}G❌\c"; err=$(( $err + 1 )); }
}


### COMPIL
echo -e "\033[36m[+] Checking compilation...\033[0m\033[50G\c"
clang -Wall -Wextra -Werror mini_serv.c -o mini_serv &> log.txt
[ "$(cat log.txt)" = "" ] && echo "✅"|| { echo -e "\033[31mCompilation error...\033[0m"; cat log.txt; rm log.txt; exit 1; }


### HANDLE ERRORS
echo -e "\n\033[36m[+] Checking errors\033[0m\033[50GExit status\033[70GDiff Output"
echo -e "\033[33m[+] Checking no arguments output...\033[0m\033[50G\c"
./mini_serv &> log.txt
check "$ARGS"

echo -e "\033[33m[+] Checking two many arguments output...\033[0m\033[50G\c"
./mini_serv 1 2 &> log.txt
check "$ARGS"

echo -e "\033[33m[+] Checking syscall error output...\033[0m\033[50G\c"
./mini_serv "$port" & > log.txt
./mini_serv "$port" &> log.txt
check "$FATAL"
echo "[+] Killing mini_serv..."
killall -q mini_serv

### SUMMARY
[ $err -eq 0 ] && echo -e "\n\033[32mAll tests passed :)\033[0m" || echo -e "\033[31m$err test(s) failed :(\033[0m"

echo -e "\n\033[1mYou now need to test yourself with \033[4mnc\033[0m\n"

### CLEAN

rm -rf mini_serv log*.txt

exit $err
