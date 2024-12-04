/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:11:05 by moabbas           #+#    #+#             */
/*   Updated: 2024/10/09 12:32:19 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main() {
    {
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		Form *b = z->makeForm("SomeRandomForm", "Clown");
		b = z->makeForm("PresidentialPardonForm", "Clown");
		// Form *b = new PresidentialPardonForm("Clown");
		// Form *c = new RobotomyRequestForm("Bender");
		// Form *d = new ShrubberyCreationForm("Christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;

		try
		{
			b->beSigned(*a);
			// b->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\n" << *b << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete z;
	}
	std::cout << "\n--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("some dude");
		// Form *d = new Form(*c);
		// Form *d = new Form("Rent Contract", 140, 100); // you are not able to construct an abstract class here

		std::cout << "\n" << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;

		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << "\n" << std::endl;
		}

		// Assistant signs the Form
		try
		{
			c->beSigned(*a);
			// a->signForm(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << "\n" << std::endl;
		}

		// CEO signs the Form
		std::cout << c << std::endl;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << "\n" << std::endl;
		}
		std::cout << c << std::endl;

		// try signing the from again
		std::cout << std::endl;
		b->signForm(*c);
		std::cout << std::endl;

		// execute the Form from assistant
		try
		{
			c->execute(*a);
			// a.executeForm(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m"  << "\n" << std::endl;
		}

		// execute Form from CEO
		try
		{
			c->execute(*b);
			// b.executeForm(*c);
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << "\n" << std::endl;
		}

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		Intern *z = new Intern();
		Form *b = z->makeForm("RobotomyRequestForm", "Bender");
		Form *c = z->makeForm("ShrubberyCreationForm", "Cristmas");
		// Form *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;
		b->beSigned(*a);
		a->signForm(*c);
		std::cout << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);
		// c->execute(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	}
	return (0);
}
