/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 07:46:31 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:13:19 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	hit_points(10), energy_points(10), attack_damage(0) {
		this->name = name;
		std::cout << "ClapTrap " << this->name << " Created"<< std::endl;
	}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " Destroyed"<< std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << "ClapTrap " << name << " has no hit points or energy left to attack." << std::endl;
		return ;
	}
	energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	hit_points -= amount;
	if (hit_points < 0)
		hit_points = 0;
    std::cout << "ClapTrap " << name << " takes " << amount <<
		" points of damage. Current HP: " << hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hit_points <= 0 || energy_points <= 0) {
            std::cout << "ClapTrap " << name <<
				" has no hit points or energy left to repair." << std::endl;
            return;
    }
	hit_points += amount;
	energy_points --;
	std::cout << "ClapTrap " << name << " repairs itself, recovering "
		<< amount << " hit points. Current HP: " << hit_points << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) {
	*this = other;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
	if (this != &other)
	{
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
		this->name = other.name;
	}
			
	return *this;
}
