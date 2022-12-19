#include "Array.hpp"
#define A_SIZE 5
#include <ctime>

#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750
int main(int, char**)
{
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//    	for (int i = 0; i < MAX_VAL; i++)
//     {
//         std::cout << numbers[i] << " ";
//     }
// 	std::cout << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;

	srand(time(NULL));
	Array<int> a(A_SIZE);
	Array<std::string> b(3);

	b[0] = "asdf";
	b[1] = "qwer";
	b[2] = "zxcv";

	for (int i = 0; i < 5; i++)
	{
		try {
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	try
	{
		b[4] = "asdf";
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	for (size_t i = 0; i < A_SIZE; i++)
		a[i] = rand() % 10;
	for (size_t i = 0; i < A_SIZE; i++)
		std::cout << a[i] << " ";


	std::cout << std::endl;

	try	{
		a[13] = 0;
	} catch (std::exception &e)	{
		std::cerr << e.what() << std::endl;
	}
	try	{
		std::cout << a[-1] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}