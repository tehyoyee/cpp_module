#include "Fixed.hpp"

const int Fixed::F_Bits = 8;

Fixed::Fixed() {
	std::cout << "Fixed Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Fixed Int constructor called" << std::endl;
	this->value = num << this->F_Bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Fixed Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->F_Bits));
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Fixed Copy constructor called" << std::endl;
	this->value = fixed.getRawBits();
}	

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Fixed Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Fixed Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return ((float)this->value / (1 << this->F_Bits)); 
}

int	Fixed::toInt(void) const {
	return (this->value >> this->F_Bits);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

	//////////////////////////////////////////////////////////
	////////////////////	overloading		//////////////////
	//////////////////////////////////////////////////////////
	
		bool Fixed::operator>(const Fixed& fixed) {
			return (this->getRawBits() > fixed.getRawBits());
		}

		bool Fixed::operator<(const Fixed& fixed) {
			return (this->getRawBits() < fixed.getRawBits());
		}

		bool Fixed::operator>=(const Fixed& fixed) {
			return (this->getRawBits() >= fixed.getRawBits());
		}

		bool Fixed::operator<=(const Fixed& fixed) {
			return (this->getRawBits() <= fixed.getRawBits());
		}

		bool Fixed::operator==(const Fixed& fixed) {
			return (this->getRawBits() == fixed.getRawBits());
		}

		bool Fixed::operator!=(const Fixed& fixed) {
			return (this->getRawBits() != fixed.getRawBits());
		}

		Fixed Fixed::operator+(const Fixed& fixed) {
			Fixed temp(this->toFloat() + fixed.toFloat());
			return (temp);
		}

		Fixed Fixed::operator-(const Fixed& fixed) {
			Fixed temp(this->toFloat() - fixed.toFloat());
			return (temp);
		}

		Fixed Fixed::operator*(const Fixed& fixed) {
			Fixed temp(this->toFloat() * fixed.toFloat());
			return (temp);
		}

		Fixed Fixed::operator/(const Fixed& fixed) {
			Fixed temp(this->toFloat() / fixed.toFloat());
			return (temp);
		}

		Fixed& Fixed::operator++() {
			++this->value;
			return *this;
		}

		const Fixed Fixed::operator++(int) {
			Fixed temp(*this);
			++this->value;
			return temp;
		}

		Fixed& Fixed::operator--() {
			--this->value;
			return *this;
		}

		const Fixed Fixed::operator--(int) {
			Fixed temp(*this);
			--this->value;
			return temp;
		}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
