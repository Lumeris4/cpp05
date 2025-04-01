/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:25:37 by lelanglo          #+#    #+#             */
/*   Updated: 2025/04/01 11:17:17 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Bureaucrat *Donald = new Bureaucrat(3 , "Coin");
	Form *test = new Form("test", 4, 4);
	std::cout << *Donald << "\n" << *test;
	try
	{
		Donald->signForm(*test);
	}
	catch(const std::exception& e)
	{
		std::cerr << " nothing "<< e.what() << '\n';
	}
	std::cout << *test;
	delete test;
	delete Donald;
	return 0;
}