#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("A", 5);
		Bureaucrat b("B", 150);
		ShrubberyCreationForm s("S");
		RobotomyRequestForm r("R");
		PresidentialPardonForm p("P");

		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << s << std::endl;
		std::cout << r << std::endl;
		std::cout << p << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		a.executeForm(s);
		b.executeForm(s);
		std::cout << std::endl;

		std::cout << s << std::endl;
		std::cout << std::endl;

		a.signForm(s);
		b.signForm(s);
		std::cout << std::endl;
		std::cout << s << std::endl;
		std::cout << std::endl;

		a.executeForm(s);
		b.executeForm(s);
		std::cout << std::endl;
		std::cout << s << std::endl;
		std::cout << std::endl;


		a.executeForm(r);
		b.executeForm(r);
		std::cout << std::endl;

		std::cout << r << std::endl;
		std::cout << std::endl;

		a.signForm(r);
		b.signForm(r);
		std::cout << std::endl;
		std::cout << r << std::endl;
		std::cout << std::endl;

		a.executeForm(r);
		b.executeForm(r);
		std::cout << std::endl;
		std::cout << r << std::endl;
		std::cout << std::endl;

		std::cout << p << std::endl;
		std::cout << std::endl;

		a.executeForm(p);
		b.executeForm(p);
		std::cout << std::endl;

		std::cout << p << std::endl;
		std::cout << std::endl;

		a.signForm(p);
		b.signForm(p);
		std::cout << std::endl;
		std::cout << p << std::endl;
		std::cout << std::endl;

		a.executeForm(p);
		b.executeForm(p);
		std::cout << std::endl;
		std::cout << p << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
