#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"

class ClapTrap {
	private:
		std::string		name;
		unsigned int	HitPoints;
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;

	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap& operator=(const ClapTrap& claptrap);		// Copy Assignment operator overloading
		ClapTrap(const ClapTrap& claptrap);					// Copy Constructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif