#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cmath>
#include <sstream>
#include <limits>
#include <iomanip>

class Convert {
	private:
		std::string input;
		char	s_char;
		int		s_int;
		float	s_float;
		double	s_double;
		bool	err;

	public:
		Convert(void);
		~Convert(void);
		Convert(std::string s);
		Convert(const Convert& convert);
		Convert& operator=(const Convert& convert);

		void setValue(std::string s);
		char getChar(void) const;
		int getInt(void) const;
		float getFloat(void) const;
		double getDouble(void) const;

		bool getErr(void) const;
		char showChar(void) const;
		int showInt(void) const;
		float showFloat(void) const;
		double showDouble(void) const;
		
		class ImpossibleException : public std::exception {
			public:
  				virtual const char* what() const throw();
		};
		class NonDisplayableException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Convert &b);

#endif
