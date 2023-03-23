#include "BitcoinExchange.hpp"

void	errorMessage(std::string str) {
	std::cerr << str << std::endl;
}

void	errorMessageDate(std::string str, std::string date) {
	std::cerr << str << date << std::endl;
}

std::map<std::string, double> readData() {
	// csv 파일 읽어 저장.
	std::map<std::string, double> data;
	std::ifstream readFile("data.csv");
	if (!readFile) {
		std::cerr << "Error: data.csv doesn't exist." << std::endl;
		exit(1);
	}
	std::string input;
	std::getline(readFile, input);
	while (std::getline(readFile, input)) {
		std::stringstream ss(input);
		std::string date, rate;
		std::getline(ss, date, ',');
		std::getline(ss, rate, ',');
		data[date] = std::stod(rate);
	}
	return data;
}

bool	isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

bool	checkDate(std::string date) {
	std::istringstream	iss(date);
	int					year, month, day;
	char				sep1, sep2;

	if (date.length() != 10 || date.substr(5, 1) == "+" || date.substr(8, 1) == "+") {
		return false;
	}
	iss >> year >> sep1 >> month >> sep2 >> day;
	if (iss.fail() || year < 2009 || (year == 2009 && month == 1 && day < 2) || (2022 < year) || (year == 2022 && month > 3) || month < 0 || month > 12 || day < 1 || day > 31 || sep1 != '-' || sep2 != '-')
		return false;
	if (isLeapYear(year) && month == 2 && day > 29) {
		return false;
	} else if (month == 2 && day > 28)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return false;
	return true;
}

double	getRatio(std::map<std::string, double> data, std::string date) {
	std::map<std::string, double>::iterator iter;
	double	prevRatio = data.begin()->second;
	int		year, month, day;

	try {
		year = stoi(date.substr(0, 4));
		month = stoi(date.substr(5, 2));
		day = stoi(date.substr(8, 2));
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	for (iter = data.begin(); iter != data.end(); iter++) {
		if (iter->first == date.substr(0, 10)) {
			return iter->second;
		} else if (year < stoi((iter->first).substr(0, 4))) {
			return prevRatio;
		} else if (year == stoi((iter->first).substr(0, 4))) {
			if (month < stoi((iter->first).substr(5, 2)))
				return prevRatio;
			else if (month == stoi((iter->first). substr(5, 2)) && day < stoi((iter->first).substr(8, 2)))
				return prevRatio;
		}
		prevRatio = iter->second;
	}
	if (year == 2022)
		return (prevRatio);
	return -1;
}

bool	checkValue(std::string value)
{
	double v;

	try {
		v = stod(value);
		if (v < 0) {
			errorMessage("Error: not a positive number");
			return false;
		} else if (v > 1000) {
			errorMessage("Error: too large a number");
			return false;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

void	operateInput(std::map<std::string, double> data, char *input) {
	std::ifstream readFile(input);
	if (!readFile) {
		errorMessage("Error: file not exist");
		exit(1);
	}
	std::string columnName;
	std::getline(readFile, columnName);
	if (columnName.compare("date | value"))	{
		errorMessage("Error: bad column argument");
		exit(1);
	}
	std::string inputString;
	while (std::getline(readFile, inputString))	{
		char				sep;
		std::string			date;
		std::string			value;
		std::istringstream	iss(inputString);
		double				ratio;

		if (!(iss >> date >> sep >> value) || sep != '|')
			errorMessageDate("Error: bad input => ", date);
		else if (!checkDate(date))
			errorMessageDate("Error: bad input => ", date);
		else if (!checkValue(value)) {}
		else {
			ratio = getRatio(data, date);
			if (ratio != -1) {
				std::cout << std::fixed;
				std::cout.precision(2);
				std::cout << date << " => " << value << " = " << stod(value) * getRatio(data, date) << std::endl;
			} else {
				std::cerr << "Error: cannot find the date" << std::endl;
			}
		}
	}
	readFile.close();
}
