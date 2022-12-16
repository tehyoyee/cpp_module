#include "Brain.hpp"

Brain::Brain() {
	std::stringstream ss;
	for (int i = 0; i < 100; i++)
	{
		ss.str(std::string());
		ss << i;
		this->ideas[i] = "ideas[" + ss.str() + "]";
	}
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain) {
	std::cout << "Brain Copy assignement operator called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.getIdeas(i);
	}
	return *this;
}

Brain::Brain(const Brain& brain) {
	std::cout << "Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.getIdeas(i);
}

std::string Brain::getIdeas(int n) const {
	return this->ideas[n];
}

void Brain::setIdeas(int n, std::string str) {
	this->ideas[n] = str;
}
