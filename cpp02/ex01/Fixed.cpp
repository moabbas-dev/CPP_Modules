/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:54:38 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/15 18:46:50 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::FRACTIONAL = 8;

Fixed::Fixed() {
	this->value = 0;
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int int_value) {
	std::cout << "Int Constructor called" << std::endl;
	this->value = int_value << FRACTIONAL;
}

Fixed::Fixed(const float float_value) {
	std::cout << "Float Constructor called" << std::endl;
	this->value = roundf(float_value * (1 << FRACTIONAL));
}

Fixed::~Fixed() {
	std::cout << "Donstructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
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

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->value) / (1 << FRACTIONAL);
}

int	Fixed::toInt(void) const {
	return this->value >> FRACTIONAL;
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
