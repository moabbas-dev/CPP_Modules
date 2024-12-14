/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:24:51 by moabbas           #+#    #+#             */
/*   Updated: 2024/12/14 18:50:52 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    PmergeMe pm;

    try {
        // Vector
		std::vector<int> vector;
        pm.processInput(argc, argv, vector, "vector");

        // Deque
		std::deque<int> deque;
        pm.processInput(argc, argv, deque, "deque");

        // List
		std::list<int> list;
        pm.processInput(argc, argv, list, "list");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
