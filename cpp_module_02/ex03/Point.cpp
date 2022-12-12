#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): x(0), y(0) {
	std::cout << "Point Default Constructor called" << std::endl;
}

Point::Point(const float x, const float y): x(x), y(y) { 
	std::cout << "Point Float Constructor called" << std::endl;
}

Point::Point(const Point& point): x(point.x), y(point.y) {
	std::cout << "Point Copy Constructor called" << std::endl;
}

Point::~Point() {
	std::cout << "Point Destructor called" << std::endl;
}

Fixed Point::getValueX() const {
	return x;
}

Fixed Point::getValueY() const {
	return y;
}

Point& Point::operator=(const Point& point) {
	std::cout << "Point Copy assignment operator called" << std::endl;
	if (this != &point)
	{
		const_cast<Fixed&>(x) = point.getValueX();
		const_cast<Fixed&>(y) = point.getValueY();
		// std::cout<< point.getValueX()<<std::endl;
		// this->x = point.getValueX();
	}
	return *this;
}
