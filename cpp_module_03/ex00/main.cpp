#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("c1");
	ClapTrap claptrap2("c2");
	
	std::cout << std::endl;

	claptrap1.attack("c2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(5);

	std::cout << std::endl;
	
	claptrap2.attack("c1");
	claptrap1.takeDamage(3);
	claptrap1.takeDamage(3);
	claptrap1.takeDamage(3);
	claptrap1.takeDamage(3);

	std::cout << std::endl;
}
