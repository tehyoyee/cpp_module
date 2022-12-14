#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "Default";
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap " << this->name << " Default Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap " << this->name << " String Contructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap& fragtrap) {
	this->name = fragtrap.name;
	this->HitPoints = fragtrap.HitPoints;
	this->EnergyPoints = fragtrap.EnergyPoints;
	this->AttackDamage = fragtrap.AttackDamage;
	std::cout << "FragTrap " << this->name << " Copy Contructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap) {
	if (this != &fragtrap)
	{
		this->name = fragtrap.name;
		this->HitPoints = fragtrap.HitPoints;
		this->EnergyPoints = fragtrap.EnergyPoints;
		this->AttackDamage = fragtrap.AttackDamage;
	}
	std::cout << "FragTrap " << this->name << " Copy Assignment Contructor called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target) {
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

void FragTrap::beRepaired(unsigned int amount) {
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

void FragTrap::highFivesGuys(void) {
	std::cout << this->name << " High Five !" << std::endl;
}
