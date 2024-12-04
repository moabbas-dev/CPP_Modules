/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:40:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 17:19:39 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Animal of type " << type << " created." << std::endl;
    brain = new Brain();
}

Cat::~Cat() {
    std::cout << "Cat destroyed." << std::endl;
    delete brain;
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
