/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:10:24 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/04 13:52:26 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

class ScalarConverter {
	private:
		ScalarConverter();
	
	public:
		static void convert(const std::string& literal);
};

bool is_char_value(const std::string& literal);
bool is_int_value(const std::string& literal);
bool is_float_value(const std::string& literal);
bool is_double_value(const std::string& literal);

#endif