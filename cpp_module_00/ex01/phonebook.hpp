/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:50:24 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/04 19:50:26 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	private:
		int index;

		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void showTrimed(std::string str);
		void addContact(int index);
		void showSingle();
		void show(int index);
};

class Phonebook {
	private:
		Contact contact[8];

	public:
		void addContact(int index);
		void show(int index);
		void showSingle(int index);
};

void showField();
void showSelected(Phonebook phonebook);

#endif
