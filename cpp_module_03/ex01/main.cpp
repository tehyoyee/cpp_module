#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav1;
	ScavTrap scav2("scav2");
	ScavTrap scav3(scav1);
	ScavTrap scav4 = scav2;

	scav2.attack("asdf");
	scav2.guardGate();
	
	scav1.attack("scav2");
	scav2.takeDamage(3);
	scav2.beRepaired(3);
	
	scav2.attack("scav1");
	scav1.takeDamage(3);
	scav1.takeDamage(3);
	scav1.takeDamage(3);
	scav1.takeDamage(3);

	// scav3.attack("asdf");
	// scav4.guardGate();
	
	// scav3.attack("scav2");
	// scav4.takeDamage(3);
	// scav4.beRepaired(3);
	
	// scav4.attack("scav1");
	// scav3.takeDamage(3);
	// scav3.takeDamage(3);
	// scav3.takeDamage(3);
	// scav3.takeDamage(3);


	// ScavTrap *scav1 = new ScavTrap;
	// ClapTrap *a = scav1;
	// a->attack("a");
	// scav1->attack("a");
	// delete a;

}