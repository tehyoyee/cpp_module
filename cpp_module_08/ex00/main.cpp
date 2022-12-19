#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}
	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " " << d[i]  << std::endl;
	try	{
		std::cout << *(easyfind(v, 5)) << " is at " << std::distance(v.begin(), easyfind(v, 5)) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		std::cout << *(easyfind(d, 5)) << " is at " << std::distance(d.begin(), easyfind(d, 5)) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << *(easyfind(l, 10)) << " is at " << std::distance(l.begin(), easyfind(l, 10)) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}