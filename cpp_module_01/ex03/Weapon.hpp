/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:01:54 by taehykim          #+#    #+#             */
/*   Updated: 2022/12/12 19:01:55 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		const std::string	&getType() const;
		void				setType(std::string type);

		Weapon(std::string type);
		Weapon();
		~Weapon();

	private:
		std::string type;
};

#endif
