/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:17:01 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 17:35:20 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/WrongAnimal.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"
#include "includes/Cat.hpp"
#include <iostream>

int main() {
    const int numAnimals = 10;  // Total number of animals
    Animal* animals[numAnimals];
    
    // Fill half with Dog objects and the other half with Cat objects
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    // Loop over and delete each AAnimal object
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();  // Call the overridden function
        delete animals[i];        // Deleting as AAnimal
    }
    
    return 0;
}