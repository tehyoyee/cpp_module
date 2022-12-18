#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("A", 51);
		Bureaucrat b("B", 49);
		Form c("C", 50, 50);
		std::cout << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;

		a.signForm(c);
		std::cout << c << std::endl;
		std::cout << std::endl;

		b.signForm(c);
		std::cout << c << std::endl;
		std::cout << std::endl;

		a.increaseGrade();
		a.signForm(c);
		std::cout << c << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
