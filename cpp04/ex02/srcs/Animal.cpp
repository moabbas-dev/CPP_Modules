/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:38:00 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 17:30:58 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"

Animal::Animal() : type("ANIMAL") {
    std::cout << "Animal created." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

std::string Animal::getType() {
    return type;
}

Animal::Animal(const Animal& other) {
    *this = other;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}