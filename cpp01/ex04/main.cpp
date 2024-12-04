/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:53:14 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 09:18:20 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "File.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./ex04 filename s1 s2" << std::endl;
		return (1);
	}
	std::string filename = std::string(argv[1]);
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	
	File file(filename, s1, s2);
	file.create_new_file();
	return 0;
}
