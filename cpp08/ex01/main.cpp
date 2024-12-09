/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:08:07 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/08 19:28:52 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(int, char**)
{
	unsigned int N = 5;
	Span sp = Span(N);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	return 0;
}
