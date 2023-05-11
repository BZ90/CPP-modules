/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:21:30 by bzawko            #+#    #+#             */
/*   Updated: 2022/11/03 10:21:31 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::displayContents()
{
	std::string	trunc;

	if (this->exists == true)
	{
		if (this->index == 0)
		std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
		std::cout << "|" << std::setw(10) << this->index;
		if (this->fName.length() > 10)
			std::cout << "|" << std::setw(9) << this->fName.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->fName;
		if (this->lName.length() > 10)
			std::cout << "|" << std::setw(9) << this->lName.substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->lName;
		if (this->nickname.length() > 10)
			std::cout << "|" << std::setw(9) << this->nickname.substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << this->nickname << "|" << std::endl;
	}
}

void	Contact::displayDetails()
{
	std::cout << "First Name: " << this->fName << std::endl;
	std::cout << "Last Name: " << this->lName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "PH. Number: " << this->phone << std::endl;
	std::cout << "Darkest Secret: " << this->secret << std::endl;
}

int	Contact::fill(int currentContact)
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	pNum;
	std::string	dSecret;

	std::cout << "Input first name: ";
	std::getline(std::cin, first);
	std::cout << "Input last name: ";
	std::getline(std::cin, last);
	std::cout << "Input nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Input phone number: ";
	std::getline(std::cin, pNum);
	std::cout << "Input darkest secret: ";
	std::getline(std::cin, dSecret);
	if (first.empty() == 1 || last.empty() == 1 || nick.empty() == 1 || pNum.empty() == 1 || dSecret.empty() == 1)
	{
		std::cout << "Empty contact not created" << std::endl;
		return (0);
	}
	else
	{
		this->fName = first;
		this->lName = last;
		this->nickname = nick;
		this->phone = pNum;
		this->secret = dSecret;
		this->index = currentContact;
		this->exists = true;
		std::cout << "Contact created" << std::endl;
		if (currentContact == 7)
			return (-7);
		else
			return (1);
	}
}
