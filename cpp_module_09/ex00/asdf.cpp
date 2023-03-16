#include <iostream>
#include <sstream>
#include <string>

int main(void)
{
	std::string kk = "1234-1234>234";
	int a;
	char b;
	int c;
	char d;
	int e;
	std::istringstream iss(kk);
	iss >> a >> b >> c >> d >> e;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
}