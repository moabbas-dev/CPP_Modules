/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:37:49 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/08 14:48:24 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T> void iter(T* arr, std::size_t len, void (*func)(T&)) {
	for (std::size_t i = 0 ;i < len; i++)
		func(arr[i]);
}

#endif