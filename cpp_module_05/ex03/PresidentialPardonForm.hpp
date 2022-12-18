#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm(void);
	
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& p_form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& p_form);
		~PresidentialPardonForm(void);

		void execute(const Bureaucrat& b) const;
};

#endif
