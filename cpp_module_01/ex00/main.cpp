#include "Zombie.hpp"

int main(void)
{
	randomChump("name");
	Zombie *heap = newZombie("asdf");
	randomChump("asdf");
	randomChump("qwer");
	delete heap;
}