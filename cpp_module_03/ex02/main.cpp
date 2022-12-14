#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main(void)
{
	FragTrap frag1;
	FragTrap frag2("frag2");
	FragTrap frag3(frag1);
	FragTrap frag4 = frag2;

	std::cout << std::endl;

	frag2.attack("asdf");
	frag2.highFivesGuys();
	
	std::cout << std::endl;

	frag1.attack("frag2");
	frag2.takeDamage(3);
	frag2.beRepaired(300);
	
	std::cout << std::endl;

	frag2.attack("frag1");
	frag1.takeDamage(3);

	std::cout << std::endl;

	// frag3.attack("asdf");
	// frag4.guardGate();
	
	// frag3.attack("frag2");
	// frag4.takeDamage(3);
	// frag4.beRepaired(3);
	
	// frag4.attack("frag1");
	// frag3.takeDamage(3);
	// frag3.takeDamage(3);
	// frag3.takeDamage(3);
	// frag3.takeDamage(3);


	// FragTrap *frag1 = new FragTrap;
	// ClapTrap *a = frag1;
	// a->attack("a");
	// frag1->attack("a");
	// delete a;

}