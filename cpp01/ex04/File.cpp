/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:59:16 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 09:44:32 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <string>
#include <fstream>
#include <iostream>

File::File(std::string filename, std::string s1, std::string s2): filename(filename), s1(s1), s2(s2) {}

File File::create_new_file() {
    std::ifstream ifs(filename.c_str(), std::ios_base::in);
    if (!ifs) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return *this;
	}
	std::string new_filename = filename + ".new";
	std::ofstream ofs(new_filename.c_str());
	if (!ofs) {
		std::cerr << "Error creating new file: " << new_filename << std::endl;
		return *this;
	}

    std::string line;
    std::string new_line;
	size_t start = 0;
	(void)start;
    while (std::getline(ifs, line)) {
        std::string new_line;
        size_t pos = 0;
        size_t start = 0;

        while ((pos = line.find(s1, start)) != std::string::npos) {
			new_line.append(line, start, pos - start);
			new_line.append(s2);
			start = pos + s1.length();
        }
        new_line.append(line, start, line.length() - start);
        ofs << new_line << std::endl;
    }
    ifs.close();
    ofs.close();
    return *this;
}
