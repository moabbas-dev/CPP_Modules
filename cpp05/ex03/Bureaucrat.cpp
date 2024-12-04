/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:29:14 by moabbas           #+#    #+#             */
/*   Updated: 2024/10/09 12:18:57 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    std::cout << name << " Created as Bureaucrate!\n";
}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << name << " Destroyed\n";
}

Bureaucrat::Bureaucrat() {

}

Bureaucrat& Bureaucrat::operator = (Bureaucrat& other) {
	if  (this != &other) 
		this->grade = other.grade;
	return *this;
}

int Bureaucrat::getGrade() const {
	return grade;
}

std::string Bureaucrat::getName() {
	return name;
}

void Bureaucrat::incrementGrade() {
	this->grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator << (std::ostream &os, Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!\n";
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooHighException &e) {
        std::cout << name << " couldn’t sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << name << " couldn’t sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form const &form) {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Failed to execute " << form.getName() << ": " << e.what() << std::endl;
    }
}
