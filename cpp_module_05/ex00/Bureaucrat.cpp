#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	std::cout << "Bureaucrat Constructor called" << std::endl;
	throw Bureaucrat::CustomException();
}

Bureaucrat::Bureaucrat(): name("default"), grade(150) {
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
	std::cout << "Bureaucrat Copy assignment called" << std::endl;

	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

std::ostream& operator<<(std::ostream& out, Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
