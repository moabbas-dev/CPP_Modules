/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:21:29 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/08 14:35:13 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

template <typename T> void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Min function template
template <typename T> const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// Max function template
template <typename T> const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}
#endif