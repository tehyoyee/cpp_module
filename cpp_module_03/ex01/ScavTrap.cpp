#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "Default";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap " << this->name << " Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap " << this->name << " String Contructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) {
	this->name = scavtrap.name;
	this->HitPoints = scavtrap.HitPoints;
	this->EnergyPoints = scavtrap.EnergyPoints;
	this->AttackDamage = scavtrap.AttackDamage;
	std::cout << "ScavTrap " << this->name << " Copy Contructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap) {
	if (this != &scavtrap)
	{
		this->name = scavtrap.name;
		this->HitPoints = scavtrap.HitPoints;
		this->EnergyPoints = scavtrap.EnergyPoints;
		this->AttackDamage = scavtrap.AttackDamage;
	}
	std::cout << "ScavTrap " << this->name << " Copy Assignment Contructor called" << std::endl;
	return *this;
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

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is in Gate keeper mode" << std::endl;
}