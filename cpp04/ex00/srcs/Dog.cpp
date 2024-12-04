/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:58:43 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:36:03 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Animal of type " << type << " created." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() {
    std::cout << "Woof woof!" << std::endl;
}

Dog::Dog(const Dog& other): Animal() {
    *this = other;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}