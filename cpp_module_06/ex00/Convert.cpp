#include "Convert.hpp"
#include <iomanip>
const char* Convert::ImpossibleException::what() const throw() {
  return "impossible";
}

const char* Convert::NonDisplayableException::what() const throw() {
  return "Non displayable";
}

Convert::Convert(void)
{
	this->s_char = 0;
	this->s_int = 0;
	this->s_float = 0;
	this->s_double = 0;
	this->err = false;
}

Convert::Convert(const Convert& obj)
{
	this->s_char = obj.getChar();
	this->s_int = obj.getInt();
	this->s_float = obj.getFloat();
	this->s_double = obj.getDouble();
	this->err = obj.getErr();
	this->err = false;

}

Convert& Convert::operator=(const Convert& obj)
{
	this->s_char = obj.getChar();
	this->s_int = obj.getInt();
	this->s_float = obj.getFloat();
	this->s_double = obj.getDouble();
	this->err = obj.getErr();
	return (*this);
}

Convert::~Convert(void)
{
}

Convert::Convert(std::string s)
{
	this->s_char = 0;
	this->s_int = 0;
	this->s_float = 0;
	this->s_double = 0;
	this->err = false;
	setValue(s);
}

void Convert::setValue(std::string s)
{
	std::string::size_type n;
	std::string::size_type f;
	std::string::size_type ff;
	
	try
	{
		this->input = s;
	}
	catch(const std::bad_alloc& e)
	{
		err = true;
		return ;
	}

	n = s.find('.');
	f = s.find('f', s.length() - 1);
	ff = s.find('f');

	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf" || input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
	{
		if (input == "nan" || input == "nanf")
		{
			s_double = std::numeric_limits<float>::quiet_NaN();
			s_float = std::numeric_limits<float>::quiet_NaN();
			return;
		}
		else
		{
			if (input[0] == '-')
			{
				s_double = -std::numeric_limits<float>::infinity();
				s_float = -std::numeric_limits<float>::infinity();
			}
			else
			{
				s_double = std::numeric_limits<float>::infinity();
				s_float = std::numeric_limits<float>::infinity();
			}
			return;
		}
	}
	if (f != ff)
	{
		err = true;
	}
	if (s.length() == 1 && !std::isdigit(static_cast<char>(s[0])))			// char 형
	{
		if (s.at(0) == 'f')
			err = true;
		s_char = static_cast<char>(s[0]);
		s_int = static_cast<int>(s_char);
		s_float = static_cast<float>(s_char);
		s_double = static_cast<double>(s_char);
		return;
	}

	if (input.back() == 'f')
	{
		for (int i = 0; i < (int)s.length() - 1; i++)
		{
			if (isalpha(s.at(i)))
			{
				err = true;
				return;
			}
		}
	}
	else if (s.length() != 1) 
	{
		for (int i = 0; i < (int)s.length(); i++)
		{
			if (isalpha(s.at(i)))
			{
				err = true;
				return;
			}
		}
	}
	s_int = atoi(s.c_str());
	// 	std::stringstream ss;
	// 	ss << s_int;
	// if (n == std::string::npos)				// int 형
	// {
	// 	std::cout << "ASDF" << std::endl;
	// 	s_int = atoi(s.c_str());
	// 	std::stringstream ss;
	// 	ss << s_int;
	// 	std::cout << ss.str() << std::endl;
	// 	std::cout << input << std::endl;
	// 	if (ss.str() != input)
	// 	{
	// 		std::cout << "ASDFSDFSD" << std::endl;
	// 		if (s_int > 0 && f == s.length() - 1)
	// 		{
	// 			std::cout << "ZXCV" << std::endl;
	// 			s_char = static_cast<char>(s_int);
	// 			s_float = static_cast<float>(s_int);
	// 			s_double = static_cast<double>(s_int);
	// 		}
	// 		else
	// 		{
	// 			err = true;
	// 			std::cout << "d"<<std::endl;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		s_char = static_cast<char>(s_int);
	// 		s_float = static_cast<float>(s_int);
	// 		s_double = static_cast<double>(s_int);
	// 	}
	// }
	// else
	// {
		const char *str = s.c_str();
		char *end = NULL;
		s_double = strtod(str, &end);
		s_int = static_cast<int>(s_double);
		s_char = static_cast<char>(s_double);
		s_float = static_cast<float>(s_double);
	// }	
}

char Convert::printChar(void) const
{
	std::stringstream ss;
	
	ss << s_int;
	if (err || std::isnan(s_double) || std::isinf(s_double))
		throw ImpossibleException();
	else if (isprint(s_int))
		return (s_char);
	else if (!isprint(s_int))
		throw NonDisplayableException();
	else
		throw ImpossibleException();
}

int Convert::printInt(void) const
{
	std::stringstream ss;
	
	ss << s_int;
	if ((ss.str() != input && input.length() > 8)|| err || std::isnan(s_double) || std::isinf(s_double))
		throw ImpossibleException();
	return (s_int);
}

float Convert::printFloat(void) const
{
	if (err)
		throw ImpossibleException();
	// if (std::isnan(s_double))
	// 	throw std::runtime_error("nanf");
	// if (std::isinf(s_double) && s_double > 0)
	// 	throw std::runtime_error("inff");
	// else if (std::isinf(s_double) && s_double < 0)
	// 	throw std::runtime_error("-inff");
	return (s_float);
}

double Convert::printDouble(void) const
{
	if (err)
		throw ImpossibleException();
	// if (std::isnan(s_double))
	// 	throw std::runtime_error("nan");
	// if (std::isinf(s_double) && s_double > 0)
	// 	throw std::runtime_error("inf");
	// else if (std::isinf(s_double) && s_double < 0)
	// 	throw std::runtime_error("-inf");
	return (s_double);	
}

char Convert::getChar(void) const
{
	return (s_char);

}

int Convert::getInt(void) const
{
	return (s_int);

}

float Convert::getFloat(void) const
{
	return (s_float);

}

double Convert::getDouble(void) const
{
	return (s_double);
	
}

bool Convert::getErr(void) const
{
	return (err);
}


std::ostream& operator<<(std::ostream &out, const Convert &b)
{
	std::stringstream ss;
	ss << b.getInt();

	try
	{
		out << "char: " << b.printChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		out << "int: " << b.printInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		if (static_cast<float>(b.getInt()) == b.getFloat())
		{
			if (ss.str().length() > 6)
			{
				out << "float: " << b.printFloat() << "f" << std::endl;
			}
			else
			{
				out << "float: " << b.printFloat() << ".0f" << std::endl;
			}
		}
		else
		{
			out << "float: " << b.printFloat() << "f" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		if (static_cast<double>(b.getInt()) == b.getDouble())
		{
			if (ss.str().length() > 6)
			{
				out << "double: " << b.printDouble() << std::endl;
			}
			else
			{
				out << "double: " << b.printDouble() << ".0" << std::endl;
			}

		}
		else
		{
			out << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << b.printDouble() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (out);
}
