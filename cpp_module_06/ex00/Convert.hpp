#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cmath>

# include <iostream>
# include <cmath>
# include <sstream>
# include <limits>

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
		char printChar(void) const;
		int printInt(void) const;
		float printFloat(void) const;
		double printDouble(void) const;
		
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
