#include "Animal.hpp"

Animal::Animal(): type("default") {
	std::cout << "Animal " << this->type << " Constructor called" << std::endl;	
}

Animal::~Animal() {
	std::cout << "Animal " << this->type << " Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal " << this->type << " Constructor called" << std::endl;
	this->type = animal.getType();
	return *this;
}

Animal::Animal(const Animal& animal):type(animal.getType()) {
	std::cout << "Animal " << this->type << " Constructor called" << std::endl;
}

void Animal::makeSound() const {std::cout << "Animal makes No Sound ! " << std::endl;}

std::string Animal::getType() const {return this->type;}
