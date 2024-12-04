/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:21:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/10/09 12:07:24 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Form;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat();
		~Bureaucrat();
		std::string getName();
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
		Bureaucrat& operator = (Bureaucrat& other);
		void executeForm(Form const &form);
		
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream &os, Bureaucrat& b);

#endif