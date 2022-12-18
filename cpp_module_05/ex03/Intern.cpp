#include "Intern.hpp"

const char * Intern::NoTypeException::what(void) const throw() {
	return ("it's is unknown form");
}

Intern::Intern(void) { }
Intern::~Intern(void) { }
Intern& Intern::operator=(const Intern& intern) { (void)intern; return *this; }
Intern::Intern(const Intern& intern) { (void)intern; }

AForm* Intern::makeForm(std::string type, std::string name)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	try {
		for (int i = 0; i < 3; i++)
		{
			if (types[i] == type) 
			{
				switch(i)
				{
					case 0:
						return new ShrubberyCreationForm(name);
						break;
					case 1:
						return new RobotomyRequestForm(name);
						break;
					case 2:
						return new PresidentialPardonForm(name);
						break;
				}
			}
		}
		throw Intern::NoTypeException();
	} catch (std::exception &e) {
		std::cerr << "intern couldn't create form because " << e.what() << "." << std::endl;
	}
	return (NULL);
}
