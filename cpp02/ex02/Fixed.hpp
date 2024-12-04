/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:41:37 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/15 19:25:11 by moabbas          ###   ########.fr       */
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
		Fixed operator + (const Fixed& fixed);
		Fixed operator - (const Fixed& fixed);
		Fixed operator * (const Fixed& fixed);
		Fixed operator / (const Fixed& fixed);
		
		bool operator < (const Fixed& fixed) const;
		bool operator > (const Fixed& fixed) const;
		bool operator <= (const Fixed& fixed) const;
		bool operator >= (const Fixed& fixed) const;
		bool operator != (const Fixed& fixed) const;
		bool operator == (const Fixed& fixed) const;

		Fixed operator ++ (void);
		Fixed operator -- (void);
		Fixed operator ++ (int);
		Fixed operator -- (int);

		static Fixed min(Fixed&, Fixed&);
		static const Fixed min(const Fixed&, const Fixed&);
		static Fixed max(Fixed&, Fixed&);
		static const Fixed max(const Fixed&, const Fixed&);
};

#endif