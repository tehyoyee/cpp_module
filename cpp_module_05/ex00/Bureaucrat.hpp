#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		int grade;

	public:
	class CustomException : public std::exception
	{
		public:
			const char* what(void) const throw()
			{
				return ("CustomException");
			}
	};
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat& b);
		Bureaucrat(const Bureaucrat& b);

		int getGrade() const;
		std::string getName() const;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);

#endif