/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:01:07 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/12 19:01:08 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	std::stringstream	ss;
	std::string	temp;

	for (int i = 0; i < 5; i++)
	{
		ss.str(std::string());
		ss << i;
		horde[i].setName(name + "[" + ss.str() + "]");
	}
	return (horde);
}
