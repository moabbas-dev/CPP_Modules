/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringRange.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:24:37 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/05 07:35:13 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringRange.hpp"
#include <limits>
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cmath>

bool StringRange::isStringInRangeInt(const std::string& str) {
	long num = atol(str.c_str());
	return num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min();
}

bool StringRange::isStringInRangeFloat(const std::string& str) {
    const std::string MAX_FLOAT_STR = "3.40282e+38";
    const std::string MIN_FLOAT_STR = "-3.40282e+38";

	return str[0] == '-' ?
	 str.size() < MIN_FLOAT_STR.size() || (str.size() == MIN_FLOAT_STR.size() && str >= MIN_FLOAT_STR) :
	 str.size() < MAX_FLOAT_STR.size() || (str.size() == MAX_FLOAT_STR.size() && str <= MAX_FLOAT_STR);
}

bool StringRange::isStringInRangeDouble(const std::string& str) {
    const std::string MAX_DOUBLE_STR = "1.7976931348623158e+308";
    const std::string MIN_DOUBLE_STR = "-1.7976931348623158e+308";

        return str[0] == '-' ? str.size() < MIN_DOUBLE_STR.size() || (str.size() == MIN_DOUBLE_STR.size() && str >= MIN_DOUBLE_STR):
        	   str.size() < MAX_DOUBLE_STR.size() || (str.size() == MAX_DOUBLE_STR.size() && str <= MAX_DOUBLE_STR);
}

bool StringRange::isNegative(const std::string& str) {
	return str.at(0) == '-';
}

bool StringRange::isStringInRangePrint(const std::string& str) {
	int num = atoi(str.c_str());
	if (num >= 32 && num <= 126)
		return true;
	return false;
}
