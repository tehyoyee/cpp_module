#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("stack");
	Zombie *zombies;

	zombies = zombieHorde(5, "ZombieHorde");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;

	return 0;
}