#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		WrongCat& operator=(const WrongCat& wrongcat);
		WrongCat(const WrongCat& wrongcat);

		void makeSound() const;
};

#endif