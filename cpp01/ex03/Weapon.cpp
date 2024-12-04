/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:14:01 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 08:23:31 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(): type("") {}

Weapon::Weapon(std::string type) {
	this->type = type;
}

std::string Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}