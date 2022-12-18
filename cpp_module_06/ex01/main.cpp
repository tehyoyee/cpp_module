#include "Data.hpp"

int main(void)
{
	Data d1(3);
	Data *d2;

	uintptr_t p1 = serialize(&d1);
	d2 = deserialize(p1);

	std::cout << d1 << std::endl;
	std::cout << *d2 << std::endl;
	return 0;
}
