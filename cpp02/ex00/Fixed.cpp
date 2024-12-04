/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:54:38 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/15 17:04:29 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() {
	this->value = 0;
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Donstructor called" << std::endl;
}

Fixed& Fixed::operator =(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
