#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>

std::map<std::string, double> readData();
void	errorMessage(std::string str);
void	errorMessageDate(std::string str, std::string date);
bool	isLeapYear(int year);
bool	checkDate(std::string date);
double	getRatio(std::map<std::string, double> data, std::string date);
bool	checkValue(std::string value);
void	operateInput(std::map<std::string, double> data, char *input);

#endif