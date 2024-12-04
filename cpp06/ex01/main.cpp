/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:55:58 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/05 07:56:48 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data dataInstance;
    dataInstance.id = 42;
    dataInstance.name = "Example";
    dataInstance.value = 3.14f;

    uintptr_t raw = Serializer::serialize(&dataInstance);
    
    Data* deserializedPtr = Serializer::deserialize(raw);

    if (deserializedPtr == &dataInstance) {
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Data ID: " << deserializedPtr->id << "\n";
        std::cout << "Data Name: " << deserializedPtr->name << "\n";
        std::cout << "Data Value: " << deserializedPtr->value << "\n";
    } else {
        std::cout << "Serialization and deserialization failed.\n";
    }

    return 0;
}