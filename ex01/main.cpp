/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:25:37 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/31 14:07:34 by lelanglo         ###   ########.fr       */
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
	Bureaucrat Donald(50 , "Coin");
	Form *test = new Form("test", 4, 4);
	std::cout << Donald << std::endl;
	try
	{
		Donald.signForm(*test);
	}
	catch(const std::exception& e)
	{
		std::cerr << " nothing "<< e.what() << '\n';
	}
	return 0;
}