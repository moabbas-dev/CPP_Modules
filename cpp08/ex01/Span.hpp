/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:36:13 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/08 19:13:24 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>

class Span {
	private:
		std::list<int> ls;
		unsigned int size;
	public: 
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		Span operator = (const Span& other);
};

#endif
