#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("claptrap1");
	ClapTrap claptrap2("claptrap2");
	
	claptrap1.attack("claptrap2");
	claptrap2.takeDamage(3);
	claptrap2.beRepaired(3);
	
	claptrap2.attack("claptrap1");
	claptrap1.takeDamage(3);
	claptrap1.takeDamage(3);
	claptrap1.takeDamage(3);
	claptrap1.takeDamage(3);

}