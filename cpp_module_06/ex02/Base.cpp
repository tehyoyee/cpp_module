#include "Base.hpp"

Base::~Base() { }

Base* generate(void)
{
	int tmp = (rand() % 3);
	Base* ret = NULL;

	if (tmp == 0)
	{
		ret = new A();
		std::cout << "Answer : A" << std::endl;
	}
	else if (tmp == 1)
	{
		ret = new B();
		std::cout << "Answer : B" << std::endl;
	}
	else
	{
		ret = new C();
		std::cout << "Answer : C" << std::endl;
	}
	return (ret);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is C\n";
}

void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference is A\n";
	}
  	catch (std::exception&) {}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference is B\n";
	}
  	catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "reference is C\n";
	}
  	catch (std::exception&) {}
}
