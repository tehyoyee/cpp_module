#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("asdf");
	ClapTrap asdf(claptrap);
	ClapTrap qwer = claptrap;
	
	claptrap.attack("asdf");
	claptrap.beRepaired(3);
	claptrap.takeDamage(3);
	claptrap.takeDamage(3);
	claptrap.takeDamage(3);
	claptrap.takeDamage(3);
	claptrap.takeDamage(3);
	claptrap.takeDamage(3);
	qwer.takeDamage(3);
	qwer.takeDamage(3);
	qwer.takeDamage(3);
	qwer.takeDamage(3);
	qwer.takeDamage(3);
	qwer.takeDamage(3);
	claptrap.attack("asdf");
}