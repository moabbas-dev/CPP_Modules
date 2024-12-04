/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:11:47 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/18 15:16:34 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "../ex00/ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		~FragTrap();
		FragTrap(std::string name);
		void attack(const std::string& target);
		void highFivesGuys(void);
		FragTrap(FragTrap& other);
		FragTrap& operator = (const FragTrap& other);
};

#endif