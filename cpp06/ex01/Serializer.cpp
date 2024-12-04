/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:52:18 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/05 08:05:18 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	// std::cout << "Constructor Called\n";
}

Serializer::~Serializer() {
	// std::cout << "Destructor Called\n";
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}