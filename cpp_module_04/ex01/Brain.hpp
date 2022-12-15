#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <sstream>
#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain& operator=(const Brain& brain);
		Brain(const Brain& brain);
		std::string getIdeas(int n) const;
};

#endif