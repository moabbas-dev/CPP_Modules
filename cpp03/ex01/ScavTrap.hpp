/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:11:47 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:13:44 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "../ex00/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		~ScavTrap();
		ScavTrap(std::string name);
		void attack(const std::string& target);
		void guardGate();
		ScavTrap(ScavTrap& other);
		ScavTrap& operator = (const ScavTrap& other);
};

#endif