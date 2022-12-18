#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		size_t len;
		T *array;
	public:
		Array(void);
		~Array(void);
		Array(size_t n);
		Array(const Array& arr);
		Array& operator=(const Array& arr);
		size_t size(void) const;
		T& operator[] (size_t i);
		const T& operator[] (size_t i) const;
};

#include "Array.tpp"

#endif
