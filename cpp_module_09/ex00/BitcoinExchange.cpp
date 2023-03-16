#include "BitcoinExchange.hpp"

void	exitError(std::string str)
{
	std::cerr << str << std::endl;
	// exit(1);
}

void	exitErrorDate(std::string str, std::string date)
{
	std::cerr << str << date << std::endl;
	// exit(1);
}

std::map<std::string, double> readData()
{
	// csv 파일 읽어 저장.
	std::map<std::string, double> data;
	// std::map<std::string, double>::iterator iter;
	std::ifstream readFile("data.csv");
	if (!readFile)
	{
		std::cerr << "Error: data.csv doesn't exist." << std::endl;
		exit(1);
	}
	std::string input;
	std::getline(readFile, input);
	while (std::getline(readFile, input))
	{
		std::stringstream ss(input);
		std::string date, rate;
		std::getline(ss, date, ',');
		std::getline(ss, rate, ',');
		data[date] = std::stod(rate);
	}
	// for (iter = data.begin(); iter != data.end(); iter++)
		// std::cout << "date : " << iter->first << " rate : " << iter->second << std::endl;
	return data;
}

bool	checkDate(std::string date)
{
	std::istringstream	iss(date);
	int					year, month, day;
	char				sep1, sep2;

	if (date.length() != 10)
		return false;
	iss >> year >> sep1 >> month >> sep2 >> day;
	if (iss.fail() || year < 0 || month < 0 || month > 12 || day < 1 || day > 31)
		return false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))		// 윤년
	{
		if (month == 2 && day > 29)
			return false;
	}
	else
	{
		if (month == 2 && day > 28)
			return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return false;
	return true;
}

bool	checkValue(std::string value)
{
	double v;

	std::cout << "asdf" << std::endl;
	try {
		v = stod(value);
		if (v < 0)
			exitError("Error: not a positive number");
		else if (v > 1000)
			exitError("Error: too large a number");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

void	operateInput(std::map<std::string, double> data, char *input)
{
	std::ifstream readFile(input);
	if (!input)
		exitError("invalid input argument");
	std::string columnName;
	std::getline(readFile, columnName);
	if (columnName.compare("date | value"))
		exitError("Error: bad column argument");
	std::string inputString;
	
	while (std::getline(readFile, inputString))
	{
		char				sep;		
		std::string			date;
		std::string			value;
		std::istringstream	iss(inputString);
		
		if (!(iss >> date >> sep >> value) || sep != '|')
			exitErrorDate("Error: bad input => ", date);
		else if (!checkDate(date))
			exitErrorDate("Error: bad input => ", date);
		else if (!checkValue(value)){}
	}
	readFile.close();
}
