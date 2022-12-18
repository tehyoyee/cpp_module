#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s_form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s_form);
		~ShrubberyCreationForm(void);

		void execute(const Bureaucrat& b) const;
};

#endif
