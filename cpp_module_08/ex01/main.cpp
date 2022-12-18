#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::vector<int> tmp;

	for (int i = 0; i < 1000; i++) 
	{
		tmp.push_back(i * 2);
	}
	Span test2 = Span(1000);
	test2.addRange(tmp.begin(), tmp.end());
	
	try
	{
		std::cout << test2.shortestSpan() << std::endl;
		std::cout << test2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}