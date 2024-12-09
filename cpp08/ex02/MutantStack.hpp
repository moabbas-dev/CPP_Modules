/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:33 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/09 11:42:20 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> > 
class MutantStack: public std::stack<T, Container> {
	public:
		MutantStack(): std::stack<T, Container>() {}
		
		MutantStack(const MutantStack& other): std::stack<T, Container>(other) {}

		~MutantStack() {
			// std::cout << "Stack destroyed\n";
		}
		
		MutantStack& operator = (const MutantStack& other) {
			std::stack<T, Container>::operator=(other);
			return *this;
		}

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }

};

#endif