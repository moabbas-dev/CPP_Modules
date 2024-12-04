/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringRange.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:22:50 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/04 16:40:43 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGRANGE
#define STRINGRANGE

#include<string>

class StringRange {
	private:
		StringRange();
	public:
		static bool isStringInRangePrint(const std::string& str);
		static bool isStringInRangeInt(const std::string& str);
		static bool isStringInRangeFloat(const std::string& str);
		static bool isStringInRangeDouble(const std::string& str);
		static bool isNegative(const std::string& str);

};
#endif