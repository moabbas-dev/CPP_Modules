/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:54:38 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/15 19:29:32 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::FRACTIONAL = 8;

Fixed::Fixed() {
	this->value = 0;
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int int_value) {
	this->value = int_value << FRACTIONAL;
}

Fixed::Fixed(const float float_value) {
	this->value = roundf(float_value * (1 << FRACTIONAL));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator = (const Fixed& other) {
	if (this != &other)
		this->value = other.value;
	return *this;
}

int Fixed::getRawBits( void ) const {
	return this->value;
}

void Fixed::setRawBits( int const raw ) {
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

Fixed Fixed::operator + (const Fixed& fixed) {
	Fixed result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator - (const Fixed& fixed) {
	Fixed result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator * (const Fixed& fixed) {
	Fixed result;
	result.setRawBits((u_int64_t(value) * u_int64_t(fixed.getRawBits())) / (1 << FRACTIONAL));
	return result;
}

Fixed Fixed::operator / (const Fixed& fixed) {
	Fixed result;
	result.setRawBits((u_int64_t(value) *  (1 << FRACTIONAL)) / fixed.getRawBits());
	return result;
}

Fixed Fixed::operator ++ (void) {
	++this->value;
	return *this;
}

Fixed Fixed::operator -- (void) {
	--this->value;
	return *this;
}

Fixed Fixed::operator -- (int) {
	Fixed temp(*this);
	value--;
	return temp;
}

Fixed Fixed::operator ++ (int) {
	Fixed temp(*this);
	value++;
	return temp;
}

bool Fixed::operator < (const Fixed& fixed) const
	{ return this->value < fixed.value; }
	
bool Fixed::operator > (const Fixed& fixed) const
	{ return this->value > fixed.value; }
	
bool Fixed::operator <= (const Fixed& fixed) const
	{ return this->value <= fixed.value; }
	
bool Fixed::operator >= (const Fixed& fixed) const
	{ return this->value >= fixed.value; }
	
bool Fixed::operator != (const Fixed& fixed) const
	{ return this->value != fixed.value; }
	
bool Fixed::operator == (const Fixed& fixed) const
	{ return this->value == fixed.value; }

Fixed Fixed::min(Fixed& a, Fixed& b) 
	{ return a < b ? a : b; }

Fixed Fixed::max(Fixed& a, Fixed& b) 
	{ return a > b ? a : b; }

Fixed const Fixed::min(const Fixed& a, const Fixed& b) 
	{ return a < b ? a : b; }

Fixed const Fixed::max(const Fixed& a, const Fixed& b) 
	{ return a > b ? a : b; }
