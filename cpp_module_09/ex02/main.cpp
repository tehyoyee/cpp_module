#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Error: it needs arguments" << std::endl;
		exit(1);
	}

	std::vector<int>	v;
	std::list<int>		l;

	try {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; j < strlen(argv[i]); j++) {
				if (!isdigit(argv[i][j])) {
					std::cerr << "Error: invalid argument" << std::endl;
					exit(1);
				}
			}
			int	element = atoi(argv[i]);
			if (element <= 0) {
				std::cerr << "Error: not a positive argument" << std::endl;
			}
			v.push_back(element);
			l.push_back(element);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "<vector> Before: ";
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	std::cout << "<list> Before: ";
	for (std::list<int>::iterator iter = l.begin(); iter != l.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

    std::clock_t start_vec = std::clock();
	v = mergeSortVector(v, 0, v.size());
	// v = insertionVector(v);
    std::clock_t end_vec = std::clock();
	std::cout << "after " << std::endl;
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;



    // std::sort(vec.begin(), vec.end());
    double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << v.size() << " elements with vector sort: " << elapsed_vec << " us" << std::endl;
}