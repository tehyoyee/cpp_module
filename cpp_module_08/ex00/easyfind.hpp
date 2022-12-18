#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <deque>
#include <list>
#include <vector>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end()) 
	{
		throw std::runtime_error("the number doesn't exist.!");
	}
	return iter;
}

#endif