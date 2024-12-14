/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:05:04 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 13:19:10 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN {
	public:
		RPN();
		// RPN(const RPN& other);
		~RPN();
		// RPN& operator=(const RPN& other);
		static double solveExpression(const std::string& expression);
	private:
		static bool isOperator(const std::string& token);
    	static double performOperation(double a, double b, const std::string& op);

};

#endif