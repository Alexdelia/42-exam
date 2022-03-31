/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:56:23 by adelille          #+#    #+#             */
/*   Updated: 2022/03/31 12:16:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;

		void	setTitle(const std::string &title);

		void	introduce(void) const;

	private:
		Warlock();
		Warlock(Warlock const &other);
		Warlock	&operator=(Warlock const &other);

		std::string	name;
		std::string	title;
};

#endif
