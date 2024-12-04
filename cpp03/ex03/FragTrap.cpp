/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:11:44 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:20:21 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " Destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << "FragTrap " << name << " has no hit points or energy left to attack." << std::endl;
		return ;
	}
	energy_points--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " is now in request high 5 guys." << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(name) {
	*this = other;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
	if (this != &other)
	{
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
		this->name = other.name;
	}
			
	return *this;
}