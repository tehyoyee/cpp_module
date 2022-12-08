#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		const static int F_Bits;

	public:
		Fixed(int num);
		Fixed(const float num);
		Fixed();						// default
		~Fixed();						// destructor
		Fixed(const Fixed& fixed);			// copy constructor
		Fixed& operator=(const Fixed& fixed);	// A copy Assignment operator overload
		Fixed& operator<<(const Fixed& fixed);
		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif