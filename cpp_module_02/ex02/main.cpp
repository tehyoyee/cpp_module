#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;

	// Fixed c(3);
	// Fixed d(5);

	// std::cout << "c + d = " << c + d << std::endl;
	// std::cout << "c - d = " << c - d << std::endl;
	// std::cout << "c / d = " << c / d << std::endl;
	// std::cout << "c * d = " << c * d << std::endl;

	// if (c < d)
	// 	std::cout << "c is smaller than d" << std::endl;
	// else
	// 	std::cout << "c is not smaller than d" << std::endl;

	// if (c > d)
	// 	std::cout << "c is bigger than d" << std::endl;
	// else
	// 	std::cout << "c is not bigger than d" << std::endl;

	// if (c <= d)
	// 	std::cout << "c is smaller than d" << std::endl;
	// else
	// 	std::cout << "c is not smaller than d" << std::endl;

	// if (c >= d)
	// 	std::cout << "c is bigger than d" << std::endl;
	// else
	// 	std::cout << "c is not bigger than d" << std::endl;

	// if (c == d)
	// 	std::cout << "c and d are same " << std::endl;
	// else
	// 	std::cout << "c and d are not same. " << std::endl;

	// if (c != d)
	// 	std::cout << "c and d are not same. " << std::endl;
	// else
	// 	std::cout << "c and d are same " << std::endl;

	// std::cout << Fixed::max(c, d) << std::endl;
	// std::cout << Fixed::min(c, d) << std::endl;
}