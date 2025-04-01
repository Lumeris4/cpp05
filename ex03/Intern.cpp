/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:36:13 by lelanglo          #+#    #+#             */
/*   Updated: 2025/04/01 13:38:04 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

Intern::Intern(const Intern &copy) {(void)copy;}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

const char *Intern::FormDoesNotExist::what() const throw()
{
	return ("This Form does not exist");
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int result = 4;
	AForm *form1 = NULL;
	std::string form[3] = {"presidential pardon", "robotomy request", "shruberry creation"};
	for (int i = 0; i < 3; i++)
	{
		if (!form[i].compare(name))
			result = i;
	}
	switch (result)
	{
		case 0:
			form1 = new PresidentialPardonForm(target);
			std::cout << "Intern create presidential pardon form" << std::endl;
			break;
		case 1:
			form1 = new RobotomyRequestForm(target);
			std::cout << "Intern create robotomy request form" << std::endl;
			break;
		case 2:
			form1 = new ShrubberyCreationForm(target);
			std::cout << "Intern create shruberry creation form" << std::endl;
			break;
		default:
			throw FormDoesNotExist();
			break;
	}
	return form1;
}