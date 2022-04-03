/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:42 by adelille          #+#    #+#             */
/*   Updated: 2022/04/03 14:12:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title): name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell *>::iterator	i = this->arr.begin();
	std::map<std::string, ASpell *>::iterator	end = this->arr.end();

	while (i != end)
	{
		delete i->second;
		++i;
	}
	this->arr.clear();

	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string	&Warlock::getName(void) const
{
	return (this->name);
}

const std::string	&Warlock::getTitle(void) const
{
	return (this->title);
}

void	Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void	Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *aspell)
{
	if (aspell)
		arr.insert(std::pair<std::string, ASpell *>(aspell->getName(), aspell->clone()));
}

void	Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell *>::iterator	i = arr.find(name);

	if (i != arr.end())
		delete i->second;
	arr.erase(name);
}

void	Warlock::launchSpell(std::string name, const ATarget &atarget)
{
	ASpell	*aspell = arr[name];

	if (aspell)
		aspell->launch(atarget);
}
