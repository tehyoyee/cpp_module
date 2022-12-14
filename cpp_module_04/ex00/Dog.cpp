#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog " << this->type << " Constructor called" << std::endl;	
}

Dog::~Dog() {
	std::cout << "Dog " << this->type << " Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog " << this->type << " Constructor called" << std::endl;
	this->type = dog.getType();
	return *this;
}

Dog::Dog(const Dog& dog) {
	this->type = dog.getType();
	std::cout << "Dog " << this->type << " Constructor called" << std::endl;
}

void Dog::makeSound() const {std::cout << "Bowwow ! " << std::endl;}
