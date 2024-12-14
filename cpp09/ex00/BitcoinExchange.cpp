/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:43:14 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 11:33:23 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(): prices() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): prices(other.prices) {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
	loadDatabase(databaseFile);
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "BitcoinExchange Destroyed\n";
}

void BitcoinExchange::loadDatabase(const std::string& databaseFile) {
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
	std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double rate;
        if (std::getline(iss, date, ',') && iss >> rate) {
            prices[date] = rate;
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = prices.lower_bound(date);
    if (it == prices.end() || it->first > date) {
        if (it == prices.begin())
            throw std::runtime_error("Error: no valid date found.");
        --it;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const { 
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') 
		return false;

	const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month < 1 || month > 12 || day < 1) 
		return false;

	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		maxDay = 29;

	return day <= maxDay;
}

bool BitcoinExchange::isNegativeValue (double value) const { 
	return value < 0;
}

bool BitcoinExchange::isLargeValue (double value) const { 
	return value > 2147483647;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->prices = other.prices;
	return *this;
}