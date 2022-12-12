#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		const static int F_Bits;

	public:
	//////////////////////////////////////////////////////////
	////////////////////	contructor	//////////////////////
	//////////////////////////////////////////////////////////

		Fixed();						// default
		Fixed(int num);
		Fixed(const float num);
		Fixed(const Fixed& fixed);			// copy constructor
		~Fixed();						// destructor

		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits() const;
		void setRawBits(int const raw);
	
	//////////////////////////////////////////////////////////
	////////////////////	overloading		//////////////////
	//////////////////////////////////////////////////////////
	
		bool operator>(const Fixed& fixed);
		bool operator<(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);

		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);

		Fixed& operator++();
		const Fixed operator++(int);
		Fixed& operator--();
		const Fixed operator--(int);

		Fixed& operator=(const Fixed& fixed);	// A copy Assignment operator overload
		// const Fixed& operator=(const Fixed& fixed);	// A copy Assignment operator overload
};

std::ostream& operator<<(std::ostream &out, const Fixed& fixed);

#endif