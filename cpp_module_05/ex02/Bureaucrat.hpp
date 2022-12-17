#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;
class Bureaucrat {
	private:
		const std::string name;
		int grade;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat& b);
		Bureaucrat(const Bureaucrat& b);

		int getGrade(void) const;
		std::string getName(void) const;
		void increaseGrade(void);
		void decreaseGrade(void);
	
		void signForm(Form &form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif