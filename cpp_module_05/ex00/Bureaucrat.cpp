#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade's too high.";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade's too low.";
}

Bureaucrat::Bureaucrat(void): name("default"), grade(150) {
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
	const_cast<std::string&>(name) = b.getName();
	grade = b.getGrade();
	if (this == &b)
		return (*this);
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat Copy assignment called" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): name(b.getName(), grade = b.getGrade()) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const { return name; }

int Bureaucrat::getGrade(void) const { return grade; }

void Bureaucrat::increaseGrade(void) {
	if (this->getGrade() < 2)
		throw Bureaucrat::GradeTooHighException();
	--(this->grade);
}

void Bureaucrat::decreaseGrade(void) {
	if (this->getGrade() > 149)
		throw Bureaucrat::GradeTooLowException();
	++(this->grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
