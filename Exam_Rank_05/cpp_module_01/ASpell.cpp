/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:42 by adelille          #+#    #+#             */
/*   Updated: 2022/04/01 15:39:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects)
		: name(name), effects(effects) {}

ASpell::ASpell(ASpell const &other)
{ *this = other; }

ASpell::~ASpell() {}

ASpell	&ASpell::operator=(ASpell const &other)
{
	this->name = other.name;
	this->effects = other.effects;
	return (*this);
}

const std::string	&ASpell::getName(void) const
{ return (this->name); }

const std::string	&ASpell::getEffects(void) const
{ return (this->effects); }

void	ASpell::launch(ATarget const &atarget) const
{ atarget.getHitBySpell((*this)); }
