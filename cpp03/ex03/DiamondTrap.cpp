/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:07:13 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:19:30 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " Destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->name << " and my ClapTrap name is "
		<< ClapTrap::name << "." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& other) :  ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
	*this = other;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other) {
	if (this != &other)
	{
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
		this->name = other.name;
	}
			
	return *this;
}