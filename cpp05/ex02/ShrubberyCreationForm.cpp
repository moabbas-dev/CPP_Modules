/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:23:08 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/28 13:42:51 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getGrade_execute())
		throw GradeTooLowException();
	std::ofstream of((target + "_shrubbery").c_str());
	of << "	          &&& &&  & &&\n"
       << "      && &\\/&\\|& ()|/ @, &&\n"
	   << "      &\\/(/&/&||/& /_/)_&/_&\n"
	   << "   &() &\\/&|()|/&\\/ '%\" & ()\n"
	   << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
	   << "&&   && & &| &| /& & % ()& /&&\n"
	   <<" ()&_---()&\\&\\|&&-&&--%---()~\n"
	   << "     &&     \\|||\n"
	   << "             |||\n"
	   << "             |||\n"
       << "             |||\n"
	   << "       , -=-~  .-^- _\"\n";
	of.close();
    std::cout << "Shrubbery created at " << target << std::endl;
}