/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:12:22 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/22 14:22:09 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(std::string name, int grade_sign, int grade_execute)
    : name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute) {
    if (grade_sign < 1 || grade_execute < 1) {
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150) {
        throw GradeTooLowException();
    }
}

Form::~Form() {
	std::cout << name << " Form Destroyed" << std::endl;
}

std::string Form::getName() {
	return name;
}

bool Form::getIs_signed() {
	return is_signed;
}

int Form::getGrade_sign() { 
	return this->grade_sign;
}

int Form::getGrade_execute() {
	return this->grade_execute;
}

std::ostream& operator << (std::ostream &os, Form& f) {
	os << "Name: " << f.getName()
	   << "\nGrade sign: " << f.getGrade_sign()
	   << "\nGrade Execute: " << f.getGrade_execute()
	   << "\nIs Signed: " << f.getIs_signed()
	   << std::endl;
	return os;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too High !\n";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too Low !\n";
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > grade_sign)
		throw GradeTooLowException();
	is_signed = true;
}
