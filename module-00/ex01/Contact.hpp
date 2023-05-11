/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:21:38 by bzawko            #+#    #+#             */
/*   Updated: 2022/11/03 10:21:39 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

class	Contact {
	private:
		std::string	fName;
		std::string	lName;
		std::string	nickname;
		std::string	phone;
		std::string	secret;

	public:
		Contact();
		~Contact();
		int		index;
		bool		exists;
		void	displayContents();
		void	displayDetails();
		int	fill(int currentContact);
};

#endif
