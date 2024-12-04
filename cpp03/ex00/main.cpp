/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:04:36 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/16 08:18:58 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap c("Dog");
	c.attack("Cat");
	c.takeDamage(2);
	c.takeDamage(3);
	c.beRepaired(4);
	c.takeDamage(6);
	c.takeDamage(4);
	c.takeDamage(13);
	c.beRepaired(3);
	c.takeDamage(33);
	c.attack("Cat");
	return 0;
}
