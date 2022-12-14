#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& animal);
		WrongAnimal(const WrongAnimal& animal);

		void makeSound() const;
		std::string getType() const;
};

#endif