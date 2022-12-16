#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		virtual ~Cat();
		Cat& operator=(const Cat& cat);
		Cat(const Cat& cat);

		void makeSound() const;
};

#endif