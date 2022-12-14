#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat " << this->type << " Constructor called" << std::endl;	
}

Cat::~Cat() {
	std::cout << "Cat " << this->type << " Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat " << this->type << " Constructor called" << std::endl;
	this->type = cat.getType();
	return *this;
}

Cat::Cat(const Cat& cat) {
	this->type = cat.getType();
	std::cout << "Cat " << this->type << " Constructor called" << std::endl;
}

void Cat::makeSound() const {std::cout << "Meow ! " << std::endl;}
