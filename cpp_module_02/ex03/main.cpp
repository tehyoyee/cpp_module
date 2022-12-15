// #include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point point(3.124, 235.3);
	// Point a(3, 4);
	Point b;
	b = point;
	std::cout << point.getValueX() << std::endl;
	std::cout << point.getValueY() << std::endl;
	// std::cout << b.getValueX() << std::endl;
	// std::cout << b.getValueY() << std::endl;
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}