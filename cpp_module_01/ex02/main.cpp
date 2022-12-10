#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string str2 = "asdf";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	stringREF = str2;

	std::cout << "===== Address ===== " << std::endl;
	std::cout << "str       : " << &str << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;
	
	std::cout << "===== Value =====" << std::endl;
	std::cout << "str       : " << str << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;

	return 0;
}
