#include "Data.hpp"

Data::Data(): value(0) { }
Data::~Data() { }
Data::Data(int v): value(v) { }
Data& Data::operator=(const Data& v) {
	if (this != &v)
		this->value = v.getValue();
	return *this;
}

Data::Data(const Data& v) { this->value = v.getValue(); }
int Data::getValue() const { return value; }

uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

std::ostream& operator<<(std::ostream& out, const Data& ptr) {
	out << ptr.getValue();
	return out;
}