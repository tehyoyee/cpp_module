#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <exception>
#include <cstdlib>
#include <cctype>

std::vector<int>	mergeSortVector(std::vector<int> arr, int start, int end);
std::vector<int>	insertionSortVector(std::vector<int> arr);
std::list<int>		mergeSortList(std::list<int> arr, int start, int end);
std::list<int>		insertionSortList(std::list<int> arr);

#endif