#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap " << this->name << " Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap " << this->name << " String Contructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap): name(claptrap.name), HitPoints(claptrap.HitPoints), EnergyPoints(claptrap.EnergyPoints), AttackDamage(claptrap.AttackDamage) {
	std::cout << "ClapTrap " << this->name << " Copy Constructor called"<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap) {
	std::cout << "ClapTrap " << this->name << " Copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap " << this->name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
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

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoints == 0)
		std::cout << this->name << " already died" << std::endl;
	else if (amount > this->HitPoints)
	{
		this->HitPoints = 0;
		std::cout << this->name << " died" << std::endl;
	}
	else
	{
		this->HitPoints -= amount;
		std::cout << this->name << " taked damage, causing " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
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
	if (HitPoints >= 10)
	{
		std::cout << this->name << " has full of HitPoints" << std::endl;
		this->HitPoints = 10;
	}
}
