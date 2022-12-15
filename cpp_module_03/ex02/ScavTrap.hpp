#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap& scavtrap);
		ScavTrap(ScavTrap& scavtrap);
		
		void beRepaired(unsigned int amount);
		void attack(const std::string& target);
		void guardGate();
};

#endif