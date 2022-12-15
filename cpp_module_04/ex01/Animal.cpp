#include "Animal.hpp"

Animal::Animal(): type("default") {
	std::cout << "Animal Constructor called" << std::endl;	
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal Copy assignement operator called" << std::endl;
	this->type = animal.getType();
	return *this;
}

Animal::Animal(const Animal& animal):type(animal.getType()) {
	std::cout << "Animal Constructor called" << std::endl;
}

void Animal::makeSound() const {std::cout << "Animal makes No Sound ! " << std::endl;}

std::string Animal::getType() const {return this->type;}
