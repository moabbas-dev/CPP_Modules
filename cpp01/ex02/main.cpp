/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:02:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 08:08:44 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << "\n" << std::endl;

	// stringREF.append(" ffff");
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of stringPTR: " << stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF<< std::endl;
	// stringREF: This is a reference to str, which acts as an alias./
	// Any operation done through stringREF is directly applied to str.
	return 0;
}
