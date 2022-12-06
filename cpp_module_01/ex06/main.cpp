#include "Harl.hpp"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Type a argument" << std::endl;
		std::exit(1);
	}
	harl.complain(argv[1]);
}