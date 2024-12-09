/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:04:59 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/08 18:34:36 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <vector>
#include <list>
#include <map>

int main() {
    try {
        std::cout << "Test case 1: [Vector]"<< std::endl;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << std::endl;

        it = easyfind(vec, 10);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "======================\n";
        std::cout << "Test case 2: [List]"<< std::endl;
        std::list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(4);
        list.push_back(5);
        std::list<int>::iterator it = easyfind(list, 3);
        std::cout << "Found value: " << *it << std::endl;

        it = easyfind(list, 10);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}