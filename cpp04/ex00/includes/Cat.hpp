/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:40:05 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 16:27:28 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "./Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();
		void makeSound();
		Cat(const Cat& other);
    	Cat& operator = (const Cat& other);
};
#endif