#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
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
		class NoSignException : public std::exception
		{
			public:
				const char * what(void) const throw();
		};

		AForm();
		virtual ~AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm& operator=(const AForm& aform);
		AForm(const AForm& aform);
		
		void beSigned(const Bureaucrat& b);

		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSign(void) const;
		void checkExecute(const Bureaucrat& b) const;
		virtual void execute(const Bureaucrat& b) const = 0;

		void setSign(bool sign);
		void setName(std::string name);
};

std::ostream& operator<<(std::ostream& out, const AForm& aform);

#endif