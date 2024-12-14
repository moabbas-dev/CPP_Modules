/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:07:38 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 13:21:00 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <cctype>
#include <sstream>

double RPN::solveExpression(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0]) && token.size() == 1) 
            stack.push(token[0] - '0');
        else if (isOperator(token)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Invalid expression");
            double a = stack.top();
			stack.pop();
            double b = stack.top();
			stack.pop();
            stack.push(performOperation(a, b, token));
        }
		else
            throw std::runtime_error("Error: Invalid token");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
    return stack.top();
}

bool RPN::isOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::performOperation(double a, double b, const std::string& op) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Error: Division by zero");
        }
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}

RPN::RPN() {
	
}

// RPN::RPN(const RPN& other) {
// 	*this = other;
// }

RPN::~RPN() {
	
}

// RPN& RPN::operator=(const RPN& other) {
// 	return *this;
// }