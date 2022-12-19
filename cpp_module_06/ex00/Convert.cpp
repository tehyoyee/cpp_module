#include "Convert.hpp"

const char* Convert::ImpossibleException::what() const throw() {
  return "impossible";
}

const char* Convert::NonDisplayableException::what() const throw() {
  return "Non displayable";
}

Convert::Convert(void): s_char(0), s_int(0), s_float(0), s_double(0), err(false) { }
Convert::Convert(const Convert& convert) {
	this->s_char = convert.getChar();
	this->s_int = convert.getInt();
	this->s_float = convert.getFloat();
	this->s_double = convert.getDouble();
	this->err = convert.getErr();
}

Convert& Convert::operator=(const Convert& convert) {
	this->s_char = convert.getChar();
	this->s_int = convert.getInt();
	this->s_float = convert.getFloat();
	this->s_double = convert.getDouble();
	this->err = convert.getErr();
	return (*this);
}

Convert::~Convert(void) { }
Convert::Convert(std::string s): s_char(0), s_int(0), s_float(0), s_double(0), err(false) {	setValue(s); }

void Convert::setValue(std::string s)
{
	std::string::size_type n;
	std::string::size_type f;
	std::string::size_type ff;

	try {
		this->input = s;
	} catch(const std::bad_alloc& e) {
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
			s_double = sqrt(-1.0);
			s_float = sqrt(-1.0);
			return;
		}
		else
		{
			if (input[0] == '-')
			{
				s_double = -1/0.0;
				s_float = -1/0.0;
			}
			else
			{
				s_double = 1/0.0;
				s_float = 1/0.0;
			}
			return;
		}
	}
	if (f != ff)
	{
		err = true;
		return ;
	}

	if (s.length() == 1 && !std::isdigit(static_cast<char>(s[0])))		// char
	{
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
			if (i == 0)
				if (s.at(0) == '+' || s.at(0) == '-')
					continue;
			if (!('0' <= s.at(i) && s.at(i) <= '9') && (s.at(i) != '.'))
			{
				err = true;
				return;
			}
		}
	}
	else if (s.length() != 1) 
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if (i == 0)
				if (s.at(0) == '+' || s.at(0) == '-')
					continue;
			if (!('0' <= s.at(i) && s.at(i) <= '9') && (s.at(i) != '.'))
			{
				err = true;
				return;
			}
		}
	}
	s_int = atoi(s.c_str());
	const char *str = s.c_str();
	s_double = strtod(str, NULL);
	s_int = static_cast<int>(s_double);
	s_char = static_cast<char>(s_double);
	s_float = static_cast<float>(s_double);
}

char Convert::showChar(void) const
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

int Convert::showInt(void) const
{
	std::stringstream ss;
	
	ss << s_int;
	if (abs(getDouble() - s_int) >= 1 || err || std::isnan(s_double) || std::isinf(s_double))
		throw ImpossibleException();
	return (s_int);
}

float Convert::showFloat(void) const
{
	if (err)
		throw ImpossibleException();
	return (s_float);
}

double Convert::showDouble(void) const
{
	if (err)
		throw ImpossibleException();
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

	try {
		out << "char: " << b.showChar() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		out << "int: " << b.showInt() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	try {
		if (static_cast<float>(b.getInt()) == b.getFloat())
		{
			if (ss.str().length() > 6)
				out << "float: " << b.showFloat() << "f" << std::endl;
			else
				out << "float: " << b.showFloat() << ".0f" << std::endl;
		}
		else
			out << "float: " << b.showFloat() << "f" <<std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	} try {
		if (static_cast<double>(b.getInt()) == b.getDouble())
		{
			if (ss.str().length() > 6)
				out << "double: " << b.showDouble();
			else
				out << "double: " << b.showDouble() << ".0";

		}
		else
			out << "double: " << std::setprecision(15) << b.showDouble();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (out);
}
