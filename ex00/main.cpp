/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:25:37 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/31 13:47:56 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *a = new Bureaucrat(150, "Patrick");
	std::cout << *a << "\n";
	try
	{
		a->promote();
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
	delete a;
	return 0;
}