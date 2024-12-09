/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:43:24 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/08 14:56:13 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Function to increment an integer by reference
void increment(int& x) {
    x += 1;
}

// Function to print an integer
void printInt( int& x) {
    std::cout << x << " ";
}

// Function to make a string uppercase
void makeUpperCase(std::string& str) {
    for (std::size_t i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]); // Modify the string directly
    }
}

// Function to print a string
void printString(std::string& str) {
    std::cout << str << " ";
}

// Function to halve a double
void halve(double& x) {
    x /= 2;
}

// Function to print a double
void printDouble(double& x) {
    std::cout << x << " ";
}

int main() {
    // Test case 1: Integer array
    std::cout << "Test case 1: Integer array" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original: ";
    ::iter(intArr, intLen, printInt);
    std::cout << std::endl;

    ::iter(intArr, intLen, increment);

    std::cout << "Modified: ";
    ::iter(intArr, intLen, printInt);
    std::cout << std::endl << std::endl;

    // Test case 2: String array
    std::cout << "Test case 2: String array" << std::endl;
    std::string strArr[] = {"hello", "world", "iter", "template"};
    std::size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "Original: ";
    ::iter(strArr, strLen, printString);
    std::cout << std::endl;

    ::iter(strArr, strLen, makeUpperCase);

    std::cout << "Modified: ";
    ::iter(strArr, strLen, printString);
    std::cout << std::endl << std::endl;

    // Test case 3: Double array
    std::cout << "Test case 3: Double array" << std::endl;
    double dblArr[] = {10.5, 20.25, 30.75, 40.0};
    std::size_t dblLen = sizeof(dblArr) / sizeof(dblArr[0]);

    std::cout << "Original: ";
    ::iter(dblArr, dblLen, printDouble);
    std::cout << std::endl;

    ::iter(dblArr, dblLen, halve);

    std::cout << "Modified: ";
    ::iter(dblArr, dblLen, printDouble);
    std::cout << std::endl << std::endl;
    return 0;
}
