/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:04:36 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/16 11:43:37 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("Diamond");
    dt.attack("Target Dummy");
    dt.whoAmI();
    dt.takeDamage(30);
    dt.beRepaired(20);
    return 0;
}

// ClapTrap Diamond_clap_name Created
// ScavTrap Diamond_clap_name created.
// FragTrap Diamond_clap_name created.
// DiamondTrap Diamond created.
// ScavTrap Diamond_clap_name attacks Target Dummy, causing 30 points of damage!
// I am DiamondTrap Diamond and my ClapTrap name is Diamond_clap_name.
// ClapTrap Diamond_clap_name takes 30 points of damage. Current HP: 70
// ClapTrap Diamond_clap_name repairs itself, recovering 20 hit points. Current HP: 90
// DiamondTrap Diamond Destroyed.
// FragTrap Diamond_clap_name Destroyed.
// ScavTrap Diamond_clap_name Destroyed.
// ClapTrap Diamond_clap_name Destroyed