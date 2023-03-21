#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>

std::map<std::string, double> readData();

void	operateInput(std::map<std::string, double> data, char *input);

#endif