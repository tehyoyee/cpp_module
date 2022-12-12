/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:01:14 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/12 19:01:14 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("stack");
	Zombie *zombies;

	zombies = zombieHorde(5, "ZombieHorde");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;

	return 0;
}
