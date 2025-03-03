/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:47:33 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/03 16:30:07 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Bureaucrat
{
	private:
	const std::string _name;
	unsigned int _grade;
	
	public:
	Bureaucrat();
	Bureaucrat(unsigned int grade, std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);
	std::string Get_Name();
	unsigned int Get_Grade();
	
	class GradeTooLoLowException: public std::exception
	{
		public:
		const char *what() const throw();
	};
	
	class GradeTooLoHighException: public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);