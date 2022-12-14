#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap s1("s1");
	ScavTrap s2("s2");
	
	std::cout << std::endl;

	s2.attack("s1");
	s1.takeDamage(20);

	std::cout << std::endl;

	s1.attack("s2");
	s2.takeDamage(20);
	s2.beRepaired(300);
	
	std::cout << std::endl;

	s2.attack("s1");
	s1.takeDamage(20);
	s1.guardGate();

	std::cout << std::endl;
}