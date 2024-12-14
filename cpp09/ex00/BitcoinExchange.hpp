/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:39:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 10:33:18 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange {
	private:
		std::map<std::string ,double> prices;
		void loadDatabase(const std::string& databaseFile);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange(const std::string& databaseFile);
		~BitcoinExchange();

		double getExchangeRate(const std::string& date) const;
		bool isValidDate(const std::string& date) const;
		bool isNegativeValue(double value) const;
		bool isLargeValue(double value) const;
		BitcoinExchange& operator=(const BitcoinExchange& other);

};
#endif