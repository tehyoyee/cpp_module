#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		std::string const name;
		bool sign;
		int const signGrade;
		int const executeGrade;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		
		Form();
		~Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form& operator=(const Form& form);
		Form(const Form& form);
		
		void beSigned(const Bureaucrat& b);

		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSign(void) const;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif