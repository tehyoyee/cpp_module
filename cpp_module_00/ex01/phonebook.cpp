#include "phonebook.hpp"
#include <sstream>		//for parsing

void Contact::show_trimed(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::right << std::setw(10) << str;
	else
	{
		std::cout << std::right << std::setw(9) << str.substr(0, 9);
		std::cout << ".";
	}
}

void Contact::show_single()
{
	std::cout << "First name : " << first_name << std::endl;
	std::cout << "Last name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone number : " << phone_number << std::endl;
	std::cout << "Darkest secret : " << darkest_secret << std::endl;
}

void Contact::add_contact(int index)
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
	show_trimed(std::to_string(index));
	std::cout << "|";
	show_trimed(last_name);
	std::cout << "|";
	show_trimed(first_name);
	std::cout << "|";
	show_trimed(nickname);
	std::cout << std::endl;
}

void Phonebook::show_single(int index)
{
	contact[index].show_single();
}

void Phonebook::add_contact(int index)
{
	contact[index].add_contact(index);
}

void Phonebook::show(int index)
{
	contact[index].show(index);
}

void show_field_name()
{
	std::cout << std::right << std::setw(10) << "Index" << "|";;
	std::cout << std::right << std::setw(10) << "First name" << "|";
	std::cout << std::right << std::setw(10) << "Last name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
}

int is_number(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return 0;
	}
	return 1;
}

void show_selected(Phonebook phonebook)
{
	int index;
	std::stringstream ss;
	std::string input;
	std::cout << "Select index (0~7) : ";
	std::getline(std::cin, input);
	if (!is_number(input))
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
	phonebook.show_single(index);
} 
