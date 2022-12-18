#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char * AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade's too high.";
}

const char * AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade's too low.";
}

const char * AForm::NoSignException::what(void) const throw()
{
	return "this form's not signed yet";
}

AForm::AForm(void): name("default"), sign(false), signGrade(150), executeGrade(150) { }

AForm::~AForm(void) { }

AForm::AForm(std::string name, int signGrade, int executeGrade):
	name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& aform) {
	if (this == &aform)
		return (*this);
	const_cast<std::string&>(name) = aform.getName();
	const_cast<int&>(signGrade) = aform.getSignGrade();
	const_cast<int&>(executeGrade) = aform.getExecuteGrade();
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	return *this;
}

AForm::AForm(const AForm& aform):
	name(aform.getName()), signGrade(aform.getSignGrade()), executeGrade(aform.getExecuteGrade()) {

	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= signGrade)
		sign = true;
	else
		throw AForm::GradeTooLowException();
}

bool AForm::getSign(void) const {
	return sign;
}

void AForm::checkExecute(const Bureaucrat& b) const
{
	if (this->sign == false)
	{
		throw NoSignException();
	}
	else if (b.getGrade() > executeGrade)
	{
		throw GradeTooLowException();
	}	
}

std::string AForm::getName(void) const { return name; }
int AForm::getSignGrade(void) const { return signGrade; }
int AForm::getExecuteGrade(void) const { return executeGrade; };
void AForm::setSign(bool sign) { this->sign = sign; }
void AForm::setName(std::string name) { const_cast<std::string&>(this->name) = name;}


std::ostream& operator<<(std::ostream& out, const AForm& aform) {
	out << aform.getName() << ", sign: " << std::boolalpha << aform.getSign() 
		<< " signGrade: " << aform.getSignGrade() 
		<< " executeGrade: " << aform.getExecuteGrade() 
		<< ".";
	return out;
}
