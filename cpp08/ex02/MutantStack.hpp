/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:33 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/09 12:42:57 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T> 
class MutantStack: public std::stack<T> {
	public:
		MutantStack(): std::stack<T>() {}
		
		MutantStack(const MutantStack& other): std::stack<T>(other) {}

		~MutantStack() {
			// std::cout << "Stack destroyed\n";
		}
		
		MutantStack& operator = (const MutantStack& other) {
			std::stack<T>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};

#endif