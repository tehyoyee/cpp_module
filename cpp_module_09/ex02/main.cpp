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

	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}