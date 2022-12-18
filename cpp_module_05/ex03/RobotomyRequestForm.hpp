#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(void);
	
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& r_form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& r_form);
		~RobotomyRequestForm(void);

		void execute(const Bureaucrat& b) const;
};

#endif
