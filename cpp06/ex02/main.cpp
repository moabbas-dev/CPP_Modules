/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:13:03 by moabbas           #+#    #+#             */
/*   Updated: 2024/11/05 08:32:57 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate() {
	int instance = std::rand() % 3;
	if (instance == 0)
		return new A;
	else if (instance == 1)
		return new B;
	return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type of p: A\n";
	else 	if (dynamic_cast<B*>(p))
		std::cout << "Type of p: B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type of p: C\n";
	else 
		std::cout << "Unknow type\n";
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "Type of p: A\n";
	} catch(std::exception &e) {
		try {
			dynamic_cast<B&>(p);
			std::cout << "Type of p: B\n";
		} catch(std::exception &e) {
			try {
				dynamic_cast<C&>(p);
				std::cout << "Type of p: C\n";
			} catch(std::exception &e){}
		}
	}
}

int main()
{
    std::srand(std::time(NULL));
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return 0;
}
