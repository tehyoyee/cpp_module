#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Constructor called" << std::endl;	
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog Copy assignement operator called" << std::endl;
	this->type = dog.getType();
	*(this->brain) = *(dog.brain);
	return *this;
}

Dog::Dog(const Dog& dog) {
	this->type = dog.getType();
	*(this->brain) = *(dog.brain);
	std::cout << "Dog Constructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Bow Wow ! " << std::endl; }

void *Dog::getBrain() const { return this->brain; }
