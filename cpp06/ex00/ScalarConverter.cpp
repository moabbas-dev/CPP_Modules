/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:13:00 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/04 20:54:25 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
#include "Converter.hpp"

void ScalarConverter::convert(const std::string& literal) {
	if (is_char_value(literal))
		Converter::convert_from_char(literal);
	else if (is_int_value(literal))
		Converter::convert_from_int(literal);
	else if (is_float_value(literal))
		Converter::convert_from_float(literal);
	else if (is_double_value(literal))
		Converter::convert_from_double(literal);
	else
		std::cout << "ERROR: Impossible to convert this input to any type!\n";
}
