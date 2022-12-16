#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	// Animal *meta[4];

	// for (int i = 0; i < 4; i++)
	// {
	// 	if (i % 2)
	// 		meta[i] = new Cat();
	// 	else
	// 		meta[i] = new Dog();
	// }
	
	// std::cout << std::endl;
	// for (int i = 0; i < 4; i++)
	// 	delete meta[i];

/////// operation overload //////////

	Dog *d1 = new Dog();
	Dog *d2 = new Dog();

	*d2 = *d1;

	std::cout << std::endl;
	std::cout << d1->getBrain()->getIdeas(0) << std::endl;
	std::cout << d2->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;
	d1->getBrain()->setIdeas(0, "asdfasdfasdf");
	std::cout << d1->getBrain()->getIdeas(0) << std::endl;
	std::cout << d2->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;

	delete d1;
	delete d2;

///////// Copy Assignment ///////////

	// Dog *d1 = new Dog();
	// Dog *d2 = new Dog(*d1);

	// std::cout << std::endl;
	// std::cout << d1->getBrain()->getIdeas(0) << std::endl;
	// std::cout << d2->getBrain()->getIdeas(0) << std::endl;
	// std::cout << std::endl;
	// d1->getBrain()->setIdeas(0, "asdfasdfasdf");
	// std::cout << d1->getBrain()->getIdeas(0) << std::endl;
	// std::cout << d2->getBrain()->getIdeas(0) << std::endl;
	// std::cout << std::endl;

	// delete d1;
	// delete d2;
}
