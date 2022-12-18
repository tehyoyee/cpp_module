#include "Span.hpp"

Span::Span(const Span& obj)
{
	this->size = obj.getSize();
	v = obj.getVector();
}

Span& Span::operator=(const Span& obj)
{
	if(this == &obj) return *this;
	this->size = obj.getSize();
	v = obj.getVector();
	return (*this);
}

Span::~Span(void)
{
	v.clear();
	std::vector<int>().swap(v);
}

Span::Span(std::size_t i)
{
	this->size = 0;
	v.reserve(i);
}

void Span::addNumber(int value)
{
	if (v.capacity() <= this->size) 
	{
		throw std::length_error("size over");
	}
	this->size++;
	v.push_back(value);
}

void Span::addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	if (v.capacity() < this->size + std::distance(begin, end)) 
	{
		throw std::length_error("size over");
	}
	v.insert(v.end(), begin, end);
}

std::size_t Span::shortestSpan() const
{
	if (v.size() <= 2)
	{
		throw std::logic_error("vector size is not over 2");
	}
	long ret = LONG_MAX;
	int prev;
	std::vector<int> tmp = v;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++) 
	{
		if (iter == tmp.begin()) 
		{
			prev = *iter;
		}
		else 
		{
			if (ret > *iter - prev) 
			{
				ret = *iter - prev;
			}
			prev = *iter;
		}
	}
	return static_cast<std::size_t>(ret);
}

std::size_t Span::longestSpan() const
{
	if (v.size() <= 2)
	{
		throw std::logic_error("vector size is not over 2");
	}
	return (*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()) );
}


std::size_t Span::getSize() const
{
	return (this->size);
}

std::vector<int> Span::getVector() const
{
	return (this->v);
}
