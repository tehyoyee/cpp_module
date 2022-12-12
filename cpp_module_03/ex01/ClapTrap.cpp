#include "ClapTrap.hpp"

// #include <iostream>

ClapTrap::ClapTrap(): name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "String Contructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap): name(claptrap.name), HitPoints(claptrap.HitPoints), EnergyPoints(claptrap.EnergyPoints), AttackDamage(claptrap.AttackDamage) {
	std::cout << "Copy Constructor called"<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &claptrap)
	{
		this->name = claptrap.name;
		this->name = claptrap.HitPoints;
		this->name = claptrap.EnergyPoints;
		this->name = claptrap.AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << this->name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->EnergyPoints == 0)
		std::cout << "ClapTrap " << this->name << " has no EnergyPoints" << std::endl;
	else if (this->HitPoints == 0)
		std::cout << "ClapTrap " << this->name << " has no HitPoints" << std::endl;
	else
	{
		--this->EnergyPoints;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoints == 0)
		std::cout << "ClapTrap " << this->name << " already died" << std::endl;
	else if (amount > this->HitPoints)
	{
		this->HitPoints = 0;
		std::cout << "ClapTrap " << this->name << " died" << std::endl;
	}
	else
	{
		this->HitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " taked Damage, causing " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->EnergyPoints == 0)
		std::cout << "ClapTrap " << this->name << " has no EnergyPoints" << std::endl;
	else if (this->HitPoints == 0)
		std::cout << "ClapTrap " << this->name << " has no HitPoints" << std::endl;
	else
	{
		--this->EnergyPoints;
		this->HitPoints += amount;
	}
	std::cout << "ClapTrap " << this->name << " has been repaired" << std::endl;
}
