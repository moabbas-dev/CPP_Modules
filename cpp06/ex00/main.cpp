/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:14:11 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/04 14:29:41 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		std::cout << "Invalid Input!\n\tUsage : ./convert YOUR_NUMBER_HERE\n";
		return (1);
	}
	ScalarConverter::convert(std::string(argv[1]));
	return (0);
}
