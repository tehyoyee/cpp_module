/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:22:51 by youjeon           #+#    #+#             */
/*   Updated: 2022/09/05 15:28:43 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) { }
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r_form) : AForm(r_form) { }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r_form) {
	if(this == &r_form) return *this;
	this->setSign(r_form.getSign());
	this->setName(r_form.getName());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	checkExecute(b);
	srand(time(NULL));
	int tmp = (rand() % 2); 

	std::cout << "driiiiiing dringggg drrrrrr...." << std::endl;
	if (tmp)
	{
		std::cout << this->getName() << " has been robotomized successfully 50\% of the time." << std::endl;
	}
	else
	{
		std::cout << this->getName() << " failed to robotomized." << std::endl;
	}
}
