#include "ScavTrap.hpp"

ScavTrap::ClapTrap(): name("Default"), HitPoints(100), EnergyPoints(50), AttackDamage(20) {
	std::cout << "Default Constructor called" << std::endl;
}

ScavTrap::ClapTrap(std::string name): name(name), HitPoints(100), EnergyPoints(50), AttackDamage(20) {
	std::cout << "String Contructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->EnergyPoints == 0)
		std::cout << "ScavTrap " << this->name << " has no EnergyPoints" << std::endl;
	else if (this->HitPoints == 0)
		std::cout << "ScavTrap " << this->name << " has no HitPoints" << std::endl;
	else
	{
		--this->EnergyPoints;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
}
