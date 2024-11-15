/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:36:10 by mdella-r          #+#    #+#             */
/*   Updated: 2024/10/29 15:05:56 by mdella-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>
#include<cctype>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for(int i = 1; i < argc; i++){
			std::string str = argv[i];
			for (int j = 0; str[j]; j++) {
				if (str[j] >= 'a' && str[j] <= 'z')
					str[j] = toupper(str[j]);
			}
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return 0;
}
