#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);		//copy constructor
		Point& operator=(const Point& point);		// copy assignment operator overload
		~Point();

		Fixed getValueX() const;
		Fixed getValueY() const;
};

#endif