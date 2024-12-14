/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:18:55 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 18:21:54 by moabbas          ###   ########.fr       */
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
			input.push_back(num);  // Use push_back instead of insert for containers like vector or deque
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

		double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << input.size()
			<< " elements with std::" << type << ": " << time << " us" << std::endl;
	}

	template <typename Container>
	static void mergeInsertSort(Container& input) {
		// Base case: if the container has fewer than two elements, it's already sorted
		if(input.size() <= 1)
			return;

		// Step 1: Divide the container into two halves
		typename Container::iterator middle = input.begin();
		std::advance(middle ,input.size() / 2); // Find the middle of the container

		// Create two temporary containers for the two halves
		Container left(input.begin() ,middle);  // First half
		Container right(middle ,input.end());  // Second half

		// Recursively sort each half
		mergeInsertSort(left);
		mergeInsertSort(right);

		// Step 2: Merge the sorted halves back into the input container
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

		// Add remaining elements from the first half
		while(i != left.end()) {
			*it = *i;
			++i;
			++it;
		}

		// Add remaining elements from the second half
		while(j != right.end()) {
			*it = *j;
			++j;
			++it;
		}
	}
};

#endif