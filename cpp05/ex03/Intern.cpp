/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:32:00 by moabbas           #+#    #+#             */
/*   Updated: 2024/10/09 12:32:52 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {std::cout << "Intern Created\n";}
Intern::~Intern() { std::cout << "Intern Destroyed\n"; }
Form* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[] =
		{"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
	Form* (*formCreators[])(std::string target) = {
		&createRobotomyRequestForm,
		&createShrubberyCreationForm,
		&createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formNames[i] << " form\n";
			return formCreators[i](target);
		}
	}
	std::cerr << "Error: Form type '" << formName << "' does not exist.\n";
	return NULL;
}

Form* Intern::createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form* Intern::createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form* Intern::createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	// nothing to copy here, since intern has no variables
	return *this;
}
