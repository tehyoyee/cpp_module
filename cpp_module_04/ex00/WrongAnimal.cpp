#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
	std::cout << "WrongAnimal " << this->type << " Constructor called" << std::endl;	
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << this->type << " Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal) {
	std::cout << "WrongAnimal " << this->type << " Constructor called" << std::endl;
	this->type = wronganimal.getType();
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal):type(wronganimal.getType()) {
	std::cout << "WrongAnimal " << this->type << " Constructor called" << std::endl;
}

void WrongAnimal::makeSound() const {std::cout << "WrongAnimal makes No Sound ! " << std::endl;}

std::string WrongAnimal::getType() const {return this->type;}
