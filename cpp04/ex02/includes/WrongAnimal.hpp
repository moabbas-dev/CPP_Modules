/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:08:35 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:30:59 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    ~WrongAnimal();
    void makeSound();
    std::string getType();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator = (const WrongAnimal& other);
};

#endif