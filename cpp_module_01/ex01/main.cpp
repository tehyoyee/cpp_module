#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("stack0");
	Zombie *zombies;

	zombies = zombieHorde(10, "asdf");
	for (int i = 0; i < 12; i++)
		zombies[i].announce();
	delete [] zombies;
}