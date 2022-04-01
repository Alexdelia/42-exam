/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:56:23 by adelille          #+#    #+#             */
/*   Updated: 2022/04/01 15:39:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		ASpell(ASpell const &other);
		virtual ~ASpell();
		ASpell	&operator=(ASpell const &other);

		const std::string	&getName(void) const;
		const std::string	&getEffects(void) const;

		virtual ASpell	*clone(void) const = 0;

		void	launch(ATarget const &atarget) const;

	protected:
		std::string	name;
		std::string	effects;
};

#endif
