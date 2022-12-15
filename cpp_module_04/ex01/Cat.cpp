#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Constructor called" << std::endl;	
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat Copy assignement operator called" << std::endl;
	this->type = cat.getType();
	*(this->brain) = *(cat.brain);
	return *this;
}

Cat::Cat(const Cat& cat) {
	this->type = cat.getType();
	*(this->brain) = *(cat.brain);
	std::cout << "Cat Constructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow ! " << std::endl; }

Brain *Cat::getBrain() const { return this->brain; }
