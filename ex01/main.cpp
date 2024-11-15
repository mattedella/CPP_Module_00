/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:13:48 by mdella-r          #+#    #+#             */
/*   Updated: 2024/10/28 12:13:49 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

int main() {
	phonebook	contact;
	std::string option;
	int 		i = 0;
	int			j = 0;

	while (1)
	{
		if (i >= 8)
			i = 0;
		if (j >= 8)
			j = 8;
		std::cout << "insert option : ";
		std::getline(std::cin, option) ;
		if (option == "ADD") {
			contact.Add(i);
			i++;
			j++;
		}
		else if (option == "SEARCH")
			contact.Search(j);
		else if (option == "EXIT")
			contact.Exit();
		if (std::cin.eof()) {
			std::cin.clear();
			std::cout << std::endl;
			break ;
		}
	}
	return 0;
}