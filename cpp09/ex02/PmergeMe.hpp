/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:18:55 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 18:47:34 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <iomanip>

class PmergeMe {
private:
	static bool printed;
public:
	PmergeMe();
	~PmergeMe();

	template <typename Container>
	static void processInput(int argc ,char* argv[] ,Container& input ,std::string type) {
		if(argc < 2)
			throw std::runtime_error("Error: No sequence provided.");
		for(int i = 1; i < argc; ++i) {
			int num;
			std::stringstream ss(argv[i]);
			if(!(ss >> num) || num < 0)
				throw std::runtime_error("Error: Invalid input. Only positive integers are allowed.");
			input.push_back(num);
		}
		if(!printed) {
			std::cout << "Before: ";
			for(typename Container::const_iterator it = input.begin(); it != input.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		clock_t start = clock();
		mergeInsertSort<Container>(input);
		clock_t end = clock();

		if(!printed) {
			std::cout << "After: ";
			for(typename Container::const_iterator it = input.begin(); it != input.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			printed = true;
		}

		double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << input.size()
			<< " elements with std::" << type << ": " << std::fixed << std::setprecision(5) << time << " us" << std::endl;
	}

	template <typename Container>
	static void mergeInsertSort(Container& input) {
		if(input.size() <= 1)
			return;

		typename Container::iterator middle = input.begin();
		std::advance(middle ,input.size() / 2);

		Container left(input.begin() ,middle);
		Container right(middle ,input.end());

		mergeInsertSort(left);
		mergeInsertSort(right);

		typename Container::iterator it = input.begin();
		typename Container::iterator i = left.begin();
		typename Container::iterator j = right.begin();

		while(i != left.end() && j != right.end()) {
			if(*i < *j) {
				*it = *i;
				++i;
			} else {
				*it = *j;
				++j;
			}
			++it;
		}
		while(i != left.end()) {
			*it = *i;
			++i;
			++it;
		}
		while(j != right.end()) {
			*it = *j;
			++j;
			++it;
		}
	}
};

#endif