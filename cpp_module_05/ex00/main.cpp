#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		try
		{
			Bureaucrat a("nameA", 151);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		Bureaucrat a("nameA", 22);
		Bureaucrat b("nameB", 3);

		std::cout << std::endl;
		
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << std::endl;

		a.decreaseGrade();
		b.increaseGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		a.decreaseGrade();
		b.increaseGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
