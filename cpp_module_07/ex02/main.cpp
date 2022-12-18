#include "Array.hpp"
#define A_SIZE 5
#include <ctime>

int main(void)
{
	srand(time(NULL));
	Array<int> a(A_SIZE);
	
	Array<std::string> b(3);
	b[0] = "asdf";
	b[1] = "qwer";
	b[2] = "zxcv";

	std::cout << b[0] << std::endl;
	try
	{
		b[4] = "asdf";
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (size_t i = 0; i < A_SIZE; i++)
	{
		a[i] = rand() % 10;
	}
	for (size_t i = 0; i < A_SIZE; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	try
	{
		a[13] = 0;
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << a[-1] << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	

}