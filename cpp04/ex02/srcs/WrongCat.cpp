/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:11:27 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:36:27 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongAnimal of type " << type << " created." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound() {
    std::cout << "Meow meow!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal() {
    *this = other;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}
