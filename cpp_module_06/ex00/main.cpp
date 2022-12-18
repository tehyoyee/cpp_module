#include "Convert.hpp"

int main(int argc, char *argv[])
{
	Convert c;
	if (argc != 2)
		std::cout << "Type like ./convert \"arg\"" << std::endl;
	else
	{
		c.setValue(argv[1]);
		std::cout << c << std::endl;
	}
	return 0;
}