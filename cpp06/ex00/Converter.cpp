/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:43:51 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/05 07:39:07 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include "StringRange.hpp"
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <climits>

void Converter::convert_from_char(const std::string& literal) {
	std::cout << "char: " << literal << std::endl;
	std::cout << "int: " << (int)literal.at(1) << std::endl;
	std::cout << "float: " << (float)literal.at(1) << ".0f" << std::endl;
	std::cout << "double: " << (double)literal.at(1) << ".0" << std::endl;
}

void Converter::convert_from_int(const std::string& literal) {
    std::istringstream iss(literal);
    long long intValue = 0;
    iss >> intValue;

    if (StringRange::isStringInRangePrint(literal))
        std::cout << "char: \'" << static_cast<char>(intValue) << "\'" << std::endl;
    else 
        std::cout << "char: Non displayable" << std::endl;
		
    if (StringRange::isStringInRangeInt(literal)) 
        std::cout << "int: " << static_cast<int>(intValue) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl;
	
    if (StringRange::isStringInRangeFloat(literal)) {
        float floatValue = static_cast<float>(intValue);
        if (!StringRange::isNegative(literal))
            std::cout << "float: " << floatValue << ".0f" << std::endl;
        else 
            std::cout << "float: -" << -floatValue << ".0f" << std::endl;
    } 
	else if (StringRange::isNegative(literal))
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: inff" << std::endl;
	
    if (StringRange::isStringInRangeDouble(literal)) {
        double doubleValue = static_cast<double>(intValue);
        if (!StringRange::isNegative(literal)) 
            std::cout << "double: " << doubleValue << ".0" << std::endl;
        else 
            std::cout << "double: -" << -doubleValue << ".0" << std::endl;

    }
	else if (StringRange::isNegative(literal))
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: inf" << std::endl;
}

void Converter::convert_from_float(const std::string& literal) {
    std::istringstream iss(literal);
    long long intValue = 0;
    iss >> intValue;
    if (StringRange::isStringInRangePrint(literal))
        std::cout << "char: \'" << static_cast<char>(intValue) << "\'" << std::endl;
	else if (literal == "nanf" || literal == "inff" || literal == "-inff")
		std::cout << "char: impossible" << std::endl;
    	else 
        std::cout << "char: Non displayable" << std::endl;
		
	if (literal == "nanf" || literal == "inff" || literal == "-inff")
        std::cout << "int: impossible" << std::endl;
    else if (StringRange::isStringInRangeInt(literal)) 
        std::cout << "int: " << static_cast<int>(intValue) << std::endl;
    	else 
        	std::cout << "int: impossible" << std::endl;

	if (literal == "nanf" || literal == "inff" || literal == "-inff")
		std::cout << "float: " << literal << std::endl;
	else if (StringRange::isStringInRangeFloat(literal))
	{
        float floatValue = static_cast<float>(intValue);
        if (!StringRange::isNegative(literal))
            std::cout << "float: " << floatValue << literal.substr(literal.find('.')) << std::endl;
        else 
            std::cout << "float: -" << -floatValue << literal.substr(literal.find('.')) << std::endl;
    } 
	else if (StringRange::isNegative(literal))
        std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: inff" << std::endl;
	
	if (literal == "nanf" || literal == "inff" || literal == "-inff")
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	else if (StringRange::isStringInRangeDouble(literal))
	{
        double doubleValue = static_cast<double>(intValue);
        if (!StringRange::isNegative(literal)) 
            std::cout << "double: " << doubleValue
			<< literal.substr(literal.find('.'), literal.length() - literal.find('.') - 1)	
			<< std::endl;
        else 
            std::cout << "double: -" << -doubleValue
			<< literal.substr(literal.find('.'), literal.length() - literal.find('.') - 1)
			<< std::endl;
    }
	else if (StringRange::isNegative(literal))
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: inf" << std::endl;
}

void Converter::convert_from_double(const std::string& literal) {
	std::istringstream iss(literal);
    long long intValue = 0;
    iss >> intValue;
    if (StringRange::isStringInRangePrint(literal))
        std::cout << "char: \'" << static_cast<char>(intValue) << "\'" << std::endl;
	else if (literal == "nan" || literal == "inf" || literal == "-inf")
		std::cout << "char: impossible" << std::endl;
    	else 
        std::cout << "char: Non displayable" << std::endl;
		
	if (literal == "nan" || literal == "inf" || literal == "-inf")
        std::cout << "int: impossible" << std::endl;
    else if (StringRange::isStringInRangeInt(literal)) 
        std::cout << "int: " << static_cast<int>(intValue) << std::endl;
    	else 
        	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "inf" || literal == "-inf")
		std::cout << "float: " << literal << "f" << std::endl;
	else if (StringRange::isStringInRangeFloat(literal))
	{
        float floatValue = static_cast<float>(intValue);
        if (!StringRange::isNegative(literal))
            std::cout << "float: " << floatValue << literal.substr(literal.find('.')) << "f" << std::endl;
        else 
            std::cout << "float: -" << -floatValue << literal.substr(literal.find('.')) << "f" << std::endl;
    } 
	else if (StringRange::isNegative(literal))
        std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: inff" << std::endl;
	
	if (literal == "nan" || literal == "inf" || literal == "-inf")
		std::cout << "double: " << literal << std::endl;
	else if (StringRange::isStringInRangeDouble(literal))
	{
        double doubleValue = static_cast<double>(intValue);
        if (!StringRange::isNegative(literal)) 
            std::cout << "double: " << doubleValue
			<< literal.substr(literal.find('.'), literal.length() - literal.find('.') - 1)	
			<< std::endl;
        else 
            std::cout << "double: -" << -doubleValue
			<< literal.substr(literal.find('.'), literal.length() - literal.find('.') - 1)
			<< std::endl;
    }
	else if (StringRange::isNegative(literal))
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: inf" << std::endl;
}