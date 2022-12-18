#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:
		int value;
		
	public:
		Data();
		~Data();
		Data(int v);
		Data& operator=(const Data& v);
		Data(const Data& v);

		int getValue() const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream& operator<<(std::ostream& o, const Data& ptr);

#endif