/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:18:55 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 15:45:35 by moabbas          ###   ########.fr       */
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

	template <typename Container> static void processInput(int argc ,char* argv[] ,Container& input ,std::string type) {
		if(argc < 2)
			throw std::runtime_error("Error: No sequence provided.");
		for(int i = 1; i < argc; ++i) {
			int num;
			std::stringstream ss(argv[i]);
			if(!(ss >> num) || num < 0)
				throw std::runtime_error("Error: Invalid input. Only positive integers are allowed.");
			input.insert(input.end() ,num);
		}
		if(!printed)
		{
			std::cout << "Before: ";
			for(typename Container::const_iterator it = input.begin(); it != input.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		Container containerCopy(input.begin() ,input.end());
		clock_t start = clock();
		mergeInsertSort<Container>(input.begin() ,input.end());
		clock_t end = clock();

		if(!printed)
		{
			std::cout << "After: ";
			for(typename Container::const_iterator it = containerCopy.begin(); it != containerCopy.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			printed = true;
		}

		double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << containerCopy.size()
			<< " elements with std::" << type << ": " << time << " us" << std::endl;
	}

	template <typename Container> static void mergeInsertSort(typename Container::iterator begin ,typename Container::iterator end) {
		// Base case: if the range has fewer than two elements, it's already sorted
		if(std::distance(begin ,end) <= 1) return;

		// Step 1: Divide the container into two halves (or chunks)
		// Use std::advance for non-random access iterators (e.g., std::list)
		typename Container::iterator middle = begin;
		std::advance(middle ,std::distance(begin ,end) / 2); // Move 'middle' to the middle position

		// Recursively call mergeInsertSort for each half
		mergeInsertSort<Container>(begin ,middle);
		mergeInsertSort<Container>(middle ,end);

		// Step 2: Merge the sorted halves
		// Temporary container to store the merged result
		Container temp(std::distance(begin ,end));

		typename Container::iterator it1 = begin;
		typename Container::iterator it2 = middle;
		typename Container::iterator itTemp = temp.begin();

		// Merge two sorted halves
		while(it1 != middle && it2 != end) {
			if(*it1 < *it2) {
				*itTemp = *it1;
				++it1;
			} else {
				*itTemp = *it2;
				++it2;
			}
			++itTemp;
		}

		// If there are any elements left in the first half, add them
		while(it1 != middle) {
			*itTemp = *it1;
			++it1;
			++itTemp;
		}

		// If there are any elements left in the second half, add them
		while(it2 != end) {
			*itTemp = *it2;
			++it2;
			++itTemp;
		}

		// Copy the merged result back into the original container
		std::copy(temp.begin() ,temp.end() ,begin);
	}
};

#endif