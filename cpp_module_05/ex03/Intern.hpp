#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		class NoTypeException : public std::exception {
			const char * what(void) const throw();
		};

		Intern(void);
		~Intern(void);
		Intern& operator=(const Intern& intern);
		Intern(const Intern& intern);

		AForm* makeForm(std::string type, std::string name);
};

#endif