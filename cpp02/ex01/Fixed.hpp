/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:41:37 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/15 16:36:50 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int value;
		static const int FRACTIONAL;
	public:	
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int int_value);
		Fixed(const float float_value);
		~Fixed();
		Fixed& operator = (const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		friend std::ostream& operator << (std::ostream& os, const Fixed& fixed);
};

#endif