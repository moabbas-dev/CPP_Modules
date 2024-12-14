/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:38:22 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 11:33:53 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc("data.csv");
        std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
            throw std::runtime_error("Error: could not open file.");

        std::string line;
		std::getline(inputFile, line);
        while (std::getline(inputFile, line)) {
			std::istringstream iss(line);
            std::string date;
            double value;
            if (std::getline(iss, date, '|') && iss >> value) {
                date = date.substr(0, date.find_last_not_of(' ') + 1);
                if (!btc.isValidDate(date)) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }
                if (btc.isNegativeValue(value)) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
				if (btc.isLargeValue(value)) {
					std::cerr << "Error: too large a number." << std::endl;
					continue;
				}

                try {
                    double rate = btc.getExchangeRate(date);
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            } else
                std::cerr << "Error: bad input => " << line << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}