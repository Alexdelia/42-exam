/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:56:23 by adelille          #+#    #+#             */
/*   Updated: 2022/04/03 14:05:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;

		void	setTitle(const std::string &title);

		void	introduce(void) const;

		void	learnSpell(ASpell *aspell);
		void	forgetSpell(std::string name);
		void	launchSpell(std::string name, const ATarget &atarget);

	private:
		Warlock();
		Warlock(Warlock const &other);
		Warlock	&operator=(Warlock const &other);

		std::string	name;
		std::string	title;

		std::map<std::string, ASpell *>	arr;
};

#endif
