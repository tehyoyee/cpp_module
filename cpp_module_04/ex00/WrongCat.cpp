#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat " << this->type << " Constructor called" << std::endl;	
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat " << this->type << " Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat) {
	std::cout << "WrongCat " << this->type << " Constructor called" << std::endl;
	this->type = wrongcat.getType();
	return *this;
}

WrongCat::WrongCat(const WrongCat& wrongcat): WrongAnimal() {
	this->type = wrongcat.getType();
	std::cout << "WrongCat " << this->type << " Constructor called" << std::endl;
}

void WrongCat::makeSound() const {std::cout << "Meow ! " << std::endl;}
