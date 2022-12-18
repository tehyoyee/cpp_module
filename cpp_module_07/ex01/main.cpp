#include "iter.hpp"

int main(void)
{
	int i[5] = {1, 2, 3, 4, 5};
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string s[5] = {"asdf", "asdf", "qwer", "zxcv", "asdf"};
	iter(i, 5, print<int>);
	std::cout << std::endl;
	iter(c, 5, print<char>);
	std::cout << std::endl;
	iter(s, sizeof(s) / sizeof(std::string), print<std::string>);
	std::cout << std::endl;
}