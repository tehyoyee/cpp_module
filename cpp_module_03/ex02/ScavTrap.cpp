#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "Default";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap Contructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& scavtrap) {
	this->name = scavtrap.name;
	this->HitPoints = scavtrap.HitPoints;
	this->EnergyPoints = scavtrap.EnergyPoints;
	this->AttackDamage = scavtrap.AttackDamage;
	std::cout << "ScavTrap Contructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap) {
	if (this != &scavtrap)
	{
		this->name = scavtrap.name;
		this->HitPoints = scavtrap.HitPoints;
		this->EnergyPoints = scavtrap.EnergyPoints;
		this->AttackDamage = scavtrap.AttackDamage;
	}
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->EnergyPoints == 0)
		std::cout << this->name << " has no EnergyPoints" << std::endl;
	else if (this->HitPoints == 0)
		std::cout << this->name << " has no HitPoints" << std::endl;
	else
	{
		--this->EnergyPoints;
		std::cout << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->EnergyPoints == 0)
		std::cout << this->name << " has no EnergyPoints" << std::endl;
	else if (this->HitPoints == 0)
		std::cout << this->name << " has no HitPoints" << std::endl;
	else
	{
		--this->EnergyPoints;
		this->HitPoints += amount;
	}
	std::cout << this->name << " has been repaired" << std::endl;
	if (HitPoints >= 100)
	{
		std::cout << this->name << " has full of HitPoints" << std::endl;
		this->HitPoints = 100;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is in Gate keeper mode" << std::endl;
}
