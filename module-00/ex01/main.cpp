/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:22:04 by bzawko            #+#    #+#             */
/*   Updated: 2022/11/03 10:27:10 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	book;

	book.curContact = 0;
	std::cout << "You are using Phonebook." << std::endl;
	std::cout << "Available commands are: ADD, SEARCH or EXIT" << std::endl;
	for (int i = 0; i < 8; i++)
		book.contacts[i].exists = false;
	while (1)
	{
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
		{
			book.curContact += book.contacts[book.curContact].fill(book.curContact);
		}
		else if (input.compare("SEARCH") == 0)
		{
			if (book.contacts[0].exists)
			{
				for (int i = 0; i < 8; i++)
					book.contacts[i].displayContents();
				std::cout << "Enter index for more details: ";
				std::getline(std::cin, input);
				if (input.empty() == 1)
					std::cout << "no input" << std::endl;
				else if (input.length() > 1 || !(input[0] >= '0' && input[0] <= '7'))
					std::cout << "Invalid index" << std::endl;
				else
				{
					if (book.contacts[input[0] - '0'].exists)
						book.contacts[input[0] - '0'].displayDetails();
					else
						std::cout << "Contact is empty" << std::endl;
				}
			}
			else
				std::cout << "No contacts to show" << std::endl;
		}
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
