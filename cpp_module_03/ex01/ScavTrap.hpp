#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap& scavtrap);
		ScavTrap(const ScavTrap& scavtrap);
		
		void guardGate();
		void attack(const std::string& target);
};

#endif