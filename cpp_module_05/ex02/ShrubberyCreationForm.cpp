/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:45:01 by youjeon           #+#    #+#             */
/*   Updated: 2022/09/05 15:28:46 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) { }
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s_form) : AForm(s_form) { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s_form) {
	if(this == &s_form)
		return *this;
	this->setSign(s_form.getSign());
	this->setName(s_form.getName());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
	checkExecute(b);
	std::ofstream ofs;
	std::string outfile;

	outfile = getName();
	outfile.append("_shrubbery"); 
	ofs.open(outfile);
	if (ofs.fail())
	{
		std::cout << "file open failed. " << outfile << std::endl;
		return ; 
	}
	
	std::string contents = 	
"               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
 \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

	ofs << contents;
	ofs.close();

	std::cout << this->getName() << " made Ascii tree file \"" << outfile << "\"." << std::endl;
}
