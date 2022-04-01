/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:42 by adelille          #+#    #+#             */
/*   Updated: 2022/04/01 15:36:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type): type(type) {}

ATarget::ATarget(ATarget const &other)
{ *this = other; }

ATarget::~ATarget() {}

ATarget	&ATarget::operator=(ATarget const &other)
{
	this->type = other.type;
	return (*this);
}

const std::string	&ATarget::getType(void) const
{ return (this->type); }

void	ATarget::getHitBySpell(ASpell const &aspell) const
{
	std::cout << this->type << " has been " << aspell.getEffects() << "!" << std::endl;
}
