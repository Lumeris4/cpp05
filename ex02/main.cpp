/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:25:37 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/20 15:21:01 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Jean_Michel(225, "Patrick");
	}
	catch(const std::exception& e)
	{
		std::cerr << "exeption caught: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat Donald(1, "Coin");
		std::cout << Donald << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " nothing "<< e.what() << '\n';
	}

	std::cout << "\n----------------------Test Form-------------------------\n\n";
		
	Bureaucrat *a = new Bureaucrat(24, "Gilbert");
	Bureaucrat *b = new Bureaucrat(1, "Leo");
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	AForm *form1 = new PresidentialPardonForm("THE GOAT");
	try
	{
		a->execute(*form1);	
	}
	catch(const std::exception& e)
	{
		std::cerr << "The Form can't be execute because " << e.what() << '\n';
	}
	a->signForm(*form1);
	try
	{
		a->execute(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "The Form can't be execute because " << e.what() << '\n';
	}
	try
	{
		b->execute(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "The Form can't be execute because " << e.what() << '\n';
	}
	delete a;
	delete b;
	delete form1;	
	return 0;
}