/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:11:05 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/28 13:42:29 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Bureaucrat john("John", 1);  // Highest rank
    Bureaucrat jane("Jane", 140); // Low rank
    try {
        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;

        // Jane tries to sign but her grade is too low
        // jane.signForm(shrubbery);
        // John signs it
        john.signForm(shrubbery);
        // Jane can't execute it
        // jane.executeForm(shrubbery);
        // John executes it
        john.executeForm(shrubbery);
    } catch (AForm::GradeTooHighException  &e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooLowException  &e) {
        std::cerr << e.what() << std::endl;
    }
    
    try{
        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        RobotomyRequestForm robotomy("John's brain");
        john.signForm(robotomy);
        john.executeForm(robotomy); // 50% success rate

        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        PresidentialPardonForm pardon("Zaphod Beeblebrox");
        john.signForm(pardon);
        john.executeForm(pardon);

    } catch (AForm::GradeTooHighException  &e) {
        std::cerr << e.what() << std::endl;
    } catch (AForm::GradeTooLowException  &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
