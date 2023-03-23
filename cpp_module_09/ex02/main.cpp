#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Error: it needs arguments" << std::endl;
		exit(1);
	}

	std::vector<int>	v;
	std::list<int>		l;
	std::deque<int>		d;

	try {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; j < (int)strlen(argv[i]); j++) {
				if (!isdigit(argv[i][j])) {
					std::cerr << "Error: invalid argument" << std::endl;
					exit(1);
				}
			}
			int	element = std::stoi(argv[i]);
			if (element <= 0) {
				std::cerr << "Error: not a positive argument" << std::endl;
				exit(1);
			}
			v.push_back(element);
			l.push_back(element);
			d.push_back(element);
		}
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit(1);
	}

	std::cout << "<deque> Before: ";
	for (std::deque<int>::iterator iter = d.begin(); iter != d.end(); iter++) {
		std::cout << *iter << " ";
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

    std::clock_t startVector = std::clock();
	v = mergeSortVector(v, 0, v.size());
    std::clock_t endVector = std::clock();
	std::clock_t	startList = std::clock();
	l = mergeSortList(l, 0, l.size());
	std::clock_t	endList = std::clock();
	std::clock_t	startDeque = std::clock();
	d = mergeSortDeque(d, 0, d.size());
	std::clock_t	endDeque = std::clock();
	std::cout << "<vector> after" << std::endl;
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "<list> after" << std::endl;
	for (std::list<int>::iterator iter = l.begin(); iter != l.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "<deque> after" << std::endl;
	for (std::deque<int>::iterator iter = d.begin(); iter != d.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << v.size() << " elements with Vector sort: " << (double)(endVector - startVector) << " us" << std::endl;
	std::cout << "Time to process a range of " << l.size() << " elements with List sort: " << (double)(endList - startList) << " us" << std::endl;
	std::cout << "Time to process a range of " << d.size() << " elements with Deque sort: " << (double)(endDeque - startDeque) << " us" << std::endl;
}
