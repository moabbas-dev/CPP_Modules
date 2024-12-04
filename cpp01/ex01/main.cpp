/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 07:52:13 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 07:59:51 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie z("GG");
	Zombie *arr = z.zombieHorde(10, "PP");
	for(int i = 0;i < 10; i++)
		arr[i].announce();
	delete[] arr;
	return 0;
}
