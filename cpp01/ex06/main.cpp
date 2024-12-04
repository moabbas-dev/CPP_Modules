/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:11:29 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 12:42:06 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl h;

    if (argc != 2)
        return std::cerr << "Usage: ./harlFilter [LEVEL]" << std::endl, 1;
    std::string level = std::string(argv[1]);
    h.complain(level);
    // h.complain("DEBUG");
    // h.complain("INFO");
    // h.complain("WARNING");
    // h.complain("ERROR");
    // h.complain("UNKNOWN");
    return 0;
}