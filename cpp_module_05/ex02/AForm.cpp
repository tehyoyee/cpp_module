#include "Form.hpp"
#include "Bureaucrat.hpp"

const char * Form::GradeTooHighException::what(void) const throw()
{
	return "Grade's too high.";
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return "Grade's too low.";
}

Form::Form(void): name("default"), signGrade(150), executeGrade(150) {
	std::cout << "Form Constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade):
	name(name), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Constructor called" << std::endl;
}

Form& Form::operator=(const Form& form) {
	if (this == &form)
		return (*this);
	const_cast<std::string&>(name) = form.getName();
	const_cast<int&>(signGrade) = form.getSignGrade();
	const_cast<int&>(executeGrade) = form.getExecuteGrade();
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Copy assignment called" << std::endl;
	return *this;
}

Form::Form(const Form& form): 
	name(form.getName()), signGrade(form.getSignGrade()), executeGrade(form.getExecuteGrade()) {

	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Constructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= signGrade)
		sign = true;
	else
		throw Form::GradeTooHighException();
}

bool Form::getSign(void) const {
	return sign;
}


std::string Form::getName(void) const { return name; }
int Form::getSignGrade(void) const { return signGrade; }
int Form::getExecuteGrade(void) const { return executeGrade; };

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << form.getName() << ", sign: " << std::boolalpha <<form.getSign() 
		<< " signGrade: " << form.getSignGrade() 
		<< " executeGrade: " << form.getExecuteGrade() 
		<< ".";
	return out;
}
