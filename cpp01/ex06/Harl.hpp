/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:00:55 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 12:37:38 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Harl::*functions[4])(void);
	public:
		Harl();
		void complain( std::string level );
};

#endif