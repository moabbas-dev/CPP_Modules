/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:12:16 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 08:23:06 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		std::string getType();
		void setType(std::string type);
};

#endif