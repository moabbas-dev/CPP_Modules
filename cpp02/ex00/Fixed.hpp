/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:41:37 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/15 10:54:16 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int value;
		static const int FRACTIONAL = 8;
	public:	
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator = (const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif