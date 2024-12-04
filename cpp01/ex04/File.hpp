/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:56:17 by moabbas           #+#    #+#             */
/*   Updated: 2024/09/14 09:19:49 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>

class File {
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		File(std::string filename, std::string s1, std::string s2);
		File create_new_file();
};

#endif