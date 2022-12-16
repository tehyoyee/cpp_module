#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat("asdf", 22);
		Bureaucrat("asdf", 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}