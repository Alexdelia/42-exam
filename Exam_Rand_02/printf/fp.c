#include <stdio.h>

int	main(void)
{
	printf("\\5s,yes = |%5s|\n", "yes");
	printf("\\2s,indeed = |%2s|\n", "indeed");
	printf("\\5.5s,yes = |%5.5s|\n", "yes");
	printf("\\2.2s,indeed = |%2.2s|\n", "indeed");
	printf("\\.5s,yes = |%.5s|\n", "yes");
	printf("\\.2s,indeed = |%.2s|\n", "indeed");
	printf("\\5.2s,indeed = |%5.2s|\n", "indeed");
	printf("\\.10,yes = |%.10s|\n", "yes");
	return (0);
}
