#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>

std::stack<int>	pileStack(char *argv);
int	operateStack(std::stack<int> stackMain);

#endif