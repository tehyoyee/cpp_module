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

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>	// for align

class Contact {
	private:
		int index;

		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void show_trimed(std::string str);
		void add_contact(int index);
		void show_single();
		void show(int index);
};

class Phonebook {
	private:
		Contact contact[8];
	public:
		void add_contact(int index);
		void show(int index);
		void show_single(int index);
};

void show_field_name();
void show_selected(Phonebook phonebook);

#endif
