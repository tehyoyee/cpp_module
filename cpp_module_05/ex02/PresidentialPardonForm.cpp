#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) { }
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p_form) : AForm(p_form) { }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p_form)
{
	if(this == &p_form)
		return *this;
	this->setSign(p_form.getSign());
	this->setName(p_form.getName());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }

void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	checkExecute(b);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
