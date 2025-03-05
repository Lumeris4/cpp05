/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:25:37 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/04 15:58:05 by lelanglo         ###   ########.fr       */
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
	try
	{
		Bureaucrat Donald(1, "Coin");
		std::cout << Donald << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " nothing "<< e.what() << '\n';
	}
	return 0;
}