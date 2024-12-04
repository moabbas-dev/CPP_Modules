/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:58:00 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:30:06 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "./Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		~Dog();
		void makeSound();
		Dog(const Dog& other);
		Dog& operator = (const Dog& other);
};
#endif