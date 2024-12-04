/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:03 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/04 18:43:38 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class Converter {
	private:
		Converter();
	public:
		static void convert_from_char(const std::string& literal);
		static void convert_from_int(const std::string& literal);
		static void convert_from_float(const std::string& literal);
		static void convert_from_double(const std::string& literal);
};

#endif