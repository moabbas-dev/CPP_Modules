/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:40:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:35:45 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Animal of type " << type << " created." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() {
    std::cout << "Meow meow!" << std::endl;
}

Cat::Cat(const Cat& other): Animal() {
    *this = other;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}
