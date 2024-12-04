/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumCheckers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:20 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/04 21:22:37 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int count_dots(const std::string& literal) {
	int count = 0;
	for (int i = 0; i < (int)literal.length(); i++)
		if (literal.at(i) == '.')
			count++;
	return (count);
}

bool is_char_value(const std::string& literal) {
	if (literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'')
		return true;
	return false;
}

bool is_int_value(const std::string& literal) {
	int ind =( literal.at(0) == '-' || literal.at(0) == '+') ? 1 : 0;
	
	for (int i = ind;i < (int)literal.length();i++) {
		if (!isdigit(literal.at(i)))
			return false;
	}
	return true;
}

bool is_float_value(const std::string& literal) {
	if (literal == "-inff" || literal == "+inff"
		|| literal == "inff" || literal == "nanf")
		return true;
	if (count_dots(literal) != 1)	
		return false;
	if (literal.at(literal.length() - 1) != 'f')
		return false;
	int ind = (literal.at(0) == '-' || literal.at(0) == '+') ? 1 : 0;
	for (int i = ind;i < (int)literal.length() - 1;i++) {
		if (literal.at(i) == '.')
			continue;
		if (!isdigit(literal.at(i)))
			return false;
	}
	return true;
}

bool is_double_value(const std::string& literal) {
	if (literal == "-inf" || literal == "+inf"
		|| literal == "inf" || literal == "nan")
		return true;
	if (count_dots(literal) != 1)	
		return false;
	int last_ind = literal.length() - 1;
	if (literal.at(last_ind) != 'd' && !isdigit(literal.at(last_ind)))
		return false;
	int ind = (literal.at(0) == '-' || literal.at(0) == '+') ? 1 : 0;
	int end = literal.at(last_ind) == 'd' ? last_ind - 1 : last_ind;
	for (int i = ind;i < end + 1;i++) {
		if (literal.at(i) == '.')
			continue;
		if (!isdigit(literal.at(i)))
			return false;
	}
	return true;
}
