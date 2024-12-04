/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:02:18 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:18:01 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap  {
	private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	
	public:
		~DiamondTrap();
		DiamondTrap(std::string name);
		void attack(const std::string& target);
		void whoAmI(void);
		DiamondTrap(DiamondTrap& other);
		DiamondTrap& operator = (const DiamondTrap& other);
};

#endif