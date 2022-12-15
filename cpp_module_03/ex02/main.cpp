#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag1("frag1");
	FragTrap frag2("frag2");

	std::cout << std::endl;

	frag2.attack("frag1");
	frag1.takeDamage(30);
	frag2.highFivesGuys();
	
	std::cout << std::endl;

	frag1.attack("frag2");
	frag2.takeDamage(30);
	frag2.beRepaired(300);
	
	std::cout << std::endl;

	frag2.attack("frag1");
	frag1.takeDamage(30);

	std::cout << std::endl;

	// FragTrap *frag1 = new FragTrap;
	// ClapTrap *a = frag1;
	// a->attack("a");
	// frag1->attack("a");
	// delete a;

}