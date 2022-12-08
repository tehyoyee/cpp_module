#include "Fixed.hpp"
#include <iostream>

const int Fixed::F_Bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->F_Bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->F_Bits));
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = fixed.getRawBits();
}	

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->F_Bits)); 
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->F_Bits);
}