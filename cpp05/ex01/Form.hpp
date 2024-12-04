/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:05:41 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/22 19:46:51 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"


class Form {
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign;
		const int grade_execute;
	


	public :
		Form(std::string name, int grade_sign, int grade_execute);
		~Form();
		std::string getName();
		bool getIs_signed();
		int getGrade_sign();
		int getGrade_execute();
		void beSigned(Bureaucrat& b);
	class GradeTooHighException: std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooLowException: std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream& operator << (std::ostream &os, Form& f);
#endif