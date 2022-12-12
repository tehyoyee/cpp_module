/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:02:20 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/12 19:02:26 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	:type(type) { }

Weapon::Weapon() { }

Weapon::~Weapon() { }

const std::string	&Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
