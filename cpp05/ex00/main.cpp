/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:41:15 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/19 19:45:33 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob;
        
        bob.incrementGrade();
        std::cout << "After incrementing grade: " << bob;

        Bureaucrat alice("Alice", 1);
        std::cout << alice;
        alice.incrementGrade();  // Should throw GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
        charlie.decrementGrade();  // Should throw GradeTooLowException
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}