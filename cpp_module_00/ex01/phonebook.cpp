/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:50:13 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/04 19:50:15 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <sstream>		//for parsing

void Contact::showTrimed(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::right << std::setw(10) << str;
	else
	{
		std::cout << std::right << std::setw(9) << str.substr(0, 9);
		std::cout << ".";
	}
}

void Contact::showSingle()
{
	std::cout << "First name : " << first_name << std::endl;
	std::cout << "Last name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone number : " << phone_number << std::endl;
	std::cout << "Darkest secret : " << darkest_secret << std::endl;
}

void Contact::addContact(int index)
{
	this->index = index;
	std::cout << "First name : ";
	std::getline(std::cin, first_name);
	std::cout << "Last name : ";
	std::getline(std::cin, last_name);
	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number : ";
	std::getline(std::cin, phone_number);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, darkest_secret);
}

void Contact::show(int index)
{
	showTrimed(std::to_string(index));
	std::cout << "|";
	showTrimed(first_name);
	std::cout << "|";
	showTrimed(last_name);
	std::cout << "|";
	showTrimed(nickname);
	std::cout << std::endl;
}

void Phonebook::showSingle(int index)
{
	contact[index].showSingle();
}

void Phonebook::addContact(int index)
{
	contact[index].addContact(index);
}

void Phonebook::show(int index)
{
	contact[index].show(index);
}

void showField()
{
	std::cout << std::right << std::setw(10) << "Index" << "|";;
	std::cout << std::right << std::setw(10) << "First name" << "|";
	std::cout << std::right << std::setw(10) << "Last name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
}

int isNumber(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return 0;
	}
	return 1;
}

void showSelected(Phonebook phonebook)
{
	int index;
	std::stringstream ss;
	std::string input;

	std::cout << "Select index (0~7) : ";
	std::getline(std::cin, input);
	if (!isNumber(input))
	{
		std::cout << "incorrect index" << std::endl;
		return;
	}
	ss << input;
	ss >> index;
	if (!(0 <= index && index <= 7))
	{
		std::cout << "out of index" << std::endl;
		return;
	}
	phonebook.showSingle(index);
} 
