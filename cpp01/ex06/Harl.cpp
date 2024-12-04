/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:03:08 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 13:09:20 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl() {
    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;
}

void Harl::debug( void ) {
	std::cout << "I love having extra steak for my"
		"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money."
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t"
		"be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free."
	"I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	enum levels_id { DEBUG, INFO, WARNING, ERROR };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int id = -1;
	for (int i = 0;i < 4 ;i++)
		if (levels[i] == level)
			id = i;
	switch (id) {
		case 0:
			id = DEBUG;
			break;
		case 1:
			id = INFO;
			break;
		case 2:
			id = WARNING;
			break;
		case 3:
			id = ERROR;
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
			return;
	}
	for (int i = id; i <= ERROR; ++i) {
		std::string level_names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		std::cout << "[" << level_names[i] << "]" << std::endl;
		(this->*functions[i])();
		std::cout << std::endl;
	}
}
