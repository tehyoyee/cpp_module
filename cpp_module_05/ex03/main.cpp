#include "Intern.hpp"

int main(void)
{
	try {
		Bureaucrat a("A", 5);
		Bureaucrat b("B", 150);
		Intern i;

		AForm *s = i.makeForm("shrubbery creation", "S");
		AForm *r = i.makeForm("robotomy request", "R");
		AForm *p = i.makeForm("presidential pardon", "P");

		if (!s || !r || !p)
			return(1);


			std::cout << std::endl;
			std::cout << std::endl;

			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << *s << std::endl;
			std::cout << *r << std::endl;
			std::cout << *p << std::endl;

			std::cout << std::endl;
			std::cout << std::endl;

			a.executeForm(*s);
			b.executeForm(*s);
			std::cout << std::endl;

			std::cout << *s << std::endl;
			std::cout << std::endl;

			a.signForm(*s);
			b.signForm(*s);
			std::cout << std::endl;
			std::cout << *s << std::endl;
			std::cout << std::endl;

			a.executeForm(*s);
			b.executeForm(*s);
			std::cout << std::endl;
			std::cout << *s << std::endl;
			std::cout << std::endl;


			a.executeForm(*r);
			b.executeForm(*r);
			std::cout << std::endl;

			std::cout << *r << std::endl;
			std::cout << std::endl;

			a.signForm(*r);
			b.signForm(*r);
			std::cout << std::endl;
			std::cout << *r << std::endl;
			std::cout << std::endl;

			a.executeForm(*r);
			b.executeForm(*r);
			std::cout << std::endl;
			std::cout << *r << std::endl;
			std::cout << std::endl;

			std::cout << *p << std::endl;
			std::cout << std::endl;

			a.executeForm(*p);
			b.executeForm(*p);
			std::cout << std::endl;

			std::cout << *p << std::endl;
			std::cout << std::endl;

			a.signForm(*p);
			b.signForm(*p);
			std::cout << std::endl;
			std::cout << *p << std::endl;
			std::cout << std::endl;

			a.executeForm(*p);
			b.executeForm(*p);
			std::cout << std::endl;
			std::cout << *p << std::endl;
			std::cout << std::endl;

		delete s;
		delete r;
		delete p;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}
