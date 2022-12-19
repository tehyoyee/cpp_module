#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	try	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


	std::vector<int> tmp;

	for (int i = 0; i < 10; i++)
		tmp.push_back(i);
	Span t = Span(10);
	t.addRange(tmp.begin(), tmp.end());

	try	{
		std::cout << t.shortestSpan() << std::endl;
		std::cout << t.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}