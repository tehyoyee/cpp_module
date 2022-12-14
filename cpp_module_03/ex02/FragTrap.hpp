#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap& operator=(const FragTrap& fragtrap);
		FragTrap(FragTrap& fragtrap);

		void beRepaired(unsigned int amount);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif