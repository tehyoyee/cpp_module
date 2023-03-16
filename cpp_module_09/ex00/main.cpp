#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	std::map<std::string, double> data;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}
	data = readData();
	operateInput(data, argv[1]);
}