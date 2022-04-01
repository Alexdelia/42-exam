/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:56:23 by adelille          #+#    #+#             */
/*   Updated: 2022/04/01 15:38:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(ATarget const &other);
		virtual ~ATarget();
		ATarget	&operator=(ATarget const &other);

		const std::string	&getType(void) const;

		virtual ATarget	*clone(void) const = 0;

		void	getHitBySpell(ASpell const &aspell) const;

	private:
		std::string	type;
};

#endif
