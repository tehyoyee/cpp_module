#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		const static int F_Bits;

	public:
		Fixed();								// default
		~Fixed();								// destructor
		Fixed(const Fixed& fixed);				// copy constructor
		Fixed& operator=(const Fixed& fixed);	// A copy Assignment operator overload
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif