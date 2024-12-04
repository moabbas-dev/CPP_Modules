/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 07:43:56 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 07:58:41 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name ) {
	Zombie *new_zs = new Zombie[N];
	for(int i = 0; i < N; i++) {
		new_zs[i].setName(name);
	}
	return new_zs;
}
