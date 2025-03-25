/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:36:13 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/25 15:19:35 by lelanglo         ###   ########.fr       */
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
	int result = 0;
	AForm *form1 = NULL;
	std::string form[3] = {"presidential pardon", "robotomy request", "shruberry creation"};
	for (int i = 0; i < 3; i++)
	{
		if (form[i] == name)
			result = i;
	}
	switch (result)
	{
		case 0:
			form1 = new PresidentialPardonForm(target);
			std::cout << "Intern create" << name << std::endl;
			break;
		case 1:
			form1 = new RobotomyRequestForm(target);
			std::cout << "Intern create" << name << std::endl;
			break;
		case 2:
			form1 = new ShrubberyCreationForm(target);
			std::cout << "Intern create" << name << std::endl;
			break;
		default:
			throw FormDoesNotExist();
			break;
	}
	return form1;
}