/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:04:36 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/16 08:38:50 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

int main() {
    // Creating a ScavTrap object
    ScavTrap scav("Scavvy");

    // Testing attack method
    scav.attack("Target1");
    
    // Testing takeDamage method (inherited from ClapTrap)
    scav.takeDamage(30);
    
    // Testing beRepaired method (inherited from ClapTrap)
    scav.beRepaired(20);
    
    // Testing attack when energy is depleted
    scav.attack("Target2");
    scav.attack("Target3");
    scav.attack("Target4"); // Depletes energy points one by one
    
    // Testing special ability guardGate
    scav.guardGate();

    // Destructor will be called automatically at the end
    return 0;
}
