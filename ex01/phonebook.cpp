/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:13:40 by mdella-r          #+#    #+#             */
/*   Updated: 2024/10/28 12:24:51 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

void phonebook::Add(int i) {
	std::string str;

	this->book[i].SetIndex(i);
	do {
		std::cout << "insert First Name: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		if (str.empty())
			std::cout << "Line not valid\n";
	} while (str.empty());
	this->book[i].SetFirstName(str);
	do {
		std::cout << "insert Last Name: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		if (str.empty())
			std::cout << "Line not valid\n";
	} while (str.empty());
	this->book[i].SetLastName(str);
	do {
		std::cout << "insert Nickname: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		if (str.empty())
			std::cout << "Line not valid\n";
	} while (str.empty());
	this->book[i].SetNickName(str);
	do {
		std::cout << "insert Phone Number: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		if (str.empty())
			std::cout << "Line not valid\n";
	} while (str.empty());
	this->book[i].SetNumber(str);
	do {
		std::cout << "insert Darkest Secret: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		if (str.empty())
			std::cout << "Line not valid\n";
	} while (str.empty());
	this->book[i].SetSecret(str);
}

std::string Truncate(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void phonebook::Search(int max)
{
	std::string option;
	int j = -1;

	if (max == 0) {
		std::cout << "No contact to search\n";
		return ;
	}
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "\n";

	for (int i = 0; i < max; i++) {
		std::cout << std::setw(10) << std::right << this->book[i].GetIndex() << "|";
		std::cout << std::setw(10) << std::right << Truncate(this->book[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << std::right << Truncate(this->book[i].GetLastName()) << "|";
		std::cout << std::setw(10) << std::right << Truncate(this->book[i].GetNickName()) << "\n";
	}
	while (1) {
		std::cout << "Select a contact index: ";
		std::getline(std::cin, option);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}
		if (option >= "0" && option <= "9")
			j = std::stoi(option);
		else {
			std::cout << "Argument not valid\n";
			continue ;
		}
		if (j < 0 || j >= max)
			std::cout << "Error: not a valid index" << std::endl;
		else {
			std::cout << "Index: " << std::right << this->book[j].GetIndex() << std::endl;
			std::cout << "First Name: " <<  std::right << this->book[j].GetFirstName() << std::endl;
			std::cout << "Last Name: " <<  std::right << this->book[j].GetLastName() << std::endl;
			std::cout << "Nickname: " <<  std::right << this->book[j].GetNickName() << std::endl;
			std::cout << "Number: " <<  std::right << this->book[j].GetNumber() << std::endl;
			std::cout << "Darkest Secret: " <<  std::right << this->book[j].GetSecret() << std::endl;
			break ;
		}
	}
}

void phonebook::Exit()
{
	exit(1);
}
