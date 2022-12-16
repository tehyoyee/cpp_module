#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal *l = new WrongCat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();
	l->makeSound();
	std::cout << std::endl;

	delete l;
	delete k;
	delete j;
	delete i;
	delete meta;
	return 0;
}