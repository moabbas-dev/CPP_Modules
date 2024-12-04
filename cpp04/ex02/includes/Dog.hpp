/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:58:00 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 17:33:36 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;

	public:
		Dog();
		~Dog();
		virtual void makeSound();
		Dog(const Dog& other);
		Dog& operator = (const Dog& other);
};
#endif