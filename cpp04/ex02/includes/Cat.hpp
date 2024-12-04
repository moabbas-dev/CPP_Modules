/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:40:05 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 17:33:39 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;

	public:
		Cat();
		~Cat();
		virtual void makeSound();
		Cat(const Cat& other);
    	Cat& operator = (const Cat& other);
};
#endif