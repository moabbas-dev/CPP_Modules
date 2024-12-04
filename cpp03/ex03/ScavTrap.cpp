/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:11:44 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:21:51 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " Destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << "ScavTrap " << name << " has no hit points or energy left to attack." << std::endl;
		return ;
	}
	energy_points--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other): ClapTrap(name) {
	*this = other;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other) {
	if (this != &other)
	{
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
		this->name = other.name;
	}
			
	return *this;
}