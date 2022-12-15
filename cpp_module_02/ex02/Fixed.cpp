#include "Fixed.hpp"

const int Fixed::F_Bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num) {
	this->value = num << this->F_Bits;
}

Fixed::Fixed(const float num) {
	this->value = roundf(num * (1 << this->F_Bits));
}

Fixed::Fixed(const Fixed& fixed) {
	this->value = fixed.getRawBits();
}	

Fixed& Fixed::operator=(const Fixed& fixed) {
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() { }

float Fixed::toFloat(void) const {
	return ((float)this->value / (1 << this->F_Bits)); 
}

int	Fixed::toInt(void) const {
	return (this->value >> this->F_Bits);
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

	//////////////////////////////////////////////////////////
	////////////////////	overloading		//////////////////
	//////////////////////////////////////////////////////////
	
		bool Fixed::operator>(const Fixed& fixed) const {
			return (this->getRawBits() > fixed.getRawBits());
		}

		bool Fixed::operator<(const Fixed& fixed) const {
			return (this->getRawBits() < fixed.getRawBits());
		}

		bool Fixed::operator>=(const Fixed& fixed) const {
			return (this->getRawBits() >= fixed.getRawBits());
		}

		bool Fixed::operator<=(const Fixed& fixed) const {
			return (this->getRawBits() <= fixed.getRawBits());
		}

		bool Fixed::operator==(const Fixed& fixed) const {
			return (this->getRawBits() == fixed.getRawBits());
		}

		bool Fixed::operator!=(const Fixed& fixed) const {
			return (this->getRawBits() != fixed.getRawBits());
		}

		Fixed Fixed::operator+(const Fixed& fixed) const {
			Fixed temp(this->toFloat() + fixed.toFloat());
			return (temp);
		}

		Fixed Fixed::operator-(const Fixed& fixed) const {
			Fixed temp(this->toFloat() - fixed.toFloat());
			return (temp);
		}

		Fixed Fixed::operator*(const Fixed& fixed) const {
			Fixed temp(this->toFloat() * fixed.toFloat());
			return (temp);
		}

		Fixed Fixed::operator/(const Fixed& fixed) const {
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

		Fixed& Fixed::min(Fixed &f1, Fixed &f2) {
			if (f1 <= f2)
				return f1;
			else
				return f2;
		}

		const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
			if (f1 <= f2)
				return f1;
			else
				return f2;
		}

		Fixed& Fixed::max(Fixed &f1, Fixed &f2) {
			if (f1 >= f2)
				return f1;
			else
				return f2;
		}

		const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
			if (f1 >= f2)
				return f1;
			else
				return f2;
		}
	
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
