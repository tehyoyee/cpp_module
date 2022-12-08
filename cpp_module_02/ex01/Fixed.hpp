#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		const static int F_Bits;

	public:
		Fixed(int x);
		Fixed();						// default
		~Fixed();						// destructor
		Fixed(Fixed& fixed);			// copy constructor
		Fixed& operator=(const Fixed& fixed);	// A copy Assignment operator overload
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif