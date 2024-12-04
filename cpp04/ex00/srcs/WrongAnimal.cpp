/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:19 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:31:48 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("ANIMAL") {
    std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed." << std::endl;
}

void WrongAnimal::makeSound() {
    std::cout << "WrongAnimal is making a sound" << std::endl;
}

std::string WrongAnimal::getType() {
    return type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}
