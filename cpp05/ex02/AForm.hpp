/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:05:41 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/28 13:13:52 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign;
		const int grade_execute;

	protected:
		AForm(std::string name, int grade_sign, int grade_execute);
		
	public :
		virtual ~AForm();
		std::string getName() const ;
		bool getIs_signed() const;
		int getGrade_sign() const;
		int getGrade_execute() const;
		void beSigned(Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException: std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator << (std::ostream &os, AForm& f);
#endif
