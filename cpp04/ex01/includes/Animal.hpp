/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:35:55 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:27:00 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();
    virtual void makeSound();
    std::string getType();
    Animal(const Animal& other);
    Animal& operator = (const Animal& other);
};

#endif