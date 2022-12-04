#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("stack0");
	randomChump("stack1");
	Zombie *heap = newZombie("heap");
	delete heap;
	system("leaks Zombie");
}