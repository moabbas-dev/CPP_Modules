/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:43:00 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/09 10:53:02 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>
#include <math.h>
#include <algorithm>

Span::Span() : ls(), size(0) {};
Span::Span(unsigned int N) {
	ls.reverse();
	size = N;
}
Span::Span(const Span& other) {
	*this = other;
}

Span::~Span() {
	// std::cout << "List Destroyed!\n";
}

void Span::addNumber(int num) {
	if (ls.size() >= size)
		throw std::overflow_error("There is no space left in the list to add more numbers.");
	ls.push_back(num);
}

int Span::shortestSpan() {
	if (ls.size() < 2) 
		throw std::length_error("Not enough numbers to find a span.");
	ls.sort();
	int shortest = std::numeric_limits<int>::max();

	for (std::list<int>::iterator it = ls.begin(); it != ls.end(); ++it) {
		 std::list<int>::iterator next = it;
        ++next;
        if (next == ls.end())
            break;
        int diff = abs(*next - *it);
		if (diff < shortest) 
			shortest = diff;
		--next;
	}

	return shortest;
}

int Span::longestSpan() {
	if (ls.size() < 2) 
		throw std::length_error("Not enough numbers to find a span."); 
	int min_val = *std::min_element(ls.begin(), ls.end());
	int max_val = *std::max_element(ls.begin(), ls.end());
	return max_val - min_val;
}

Span Span::operator = (const Span& other) {
	if (this != &other) {
		ls = other.ls;
		size = other.size;
	}
	return *this;
}
