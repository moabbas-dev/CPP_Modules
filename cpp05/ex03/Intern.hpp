/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:04 by moabbas           #+#    #+#             */
/*   Updated: 2024/10/09 12:09:30 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Form* makeForm(std::string name, std::string target);
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);

	private: 
		static Form* createRobotomyRequestForm(std::string target);
		static Form* createShrubberyCreationForm(std::string target);
		static Form* createPresidentialPardonForm(std::string target);
};

#endif