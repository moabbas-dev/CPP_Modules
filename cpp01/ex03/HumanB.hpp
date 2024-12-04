/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:15:58 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 08:43:35 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack(void);
};

#endif