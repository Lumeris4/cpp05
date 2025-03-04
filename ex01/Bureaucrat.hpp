/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:47:33 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/04 15:56:55 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Bureaucrat
{
	private:
	const std::string _name;
	int _grade;
	
	public:
	Bureaucrat();
	Bureaucrat(int grade, std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);
	std::string Get_Name() const;
	int Get_Grade() const;
	void promote();
	void demote();
	void signForm(Form &lala);
	
	class GradeTooLowException: public std::exception
	{
		public:
		const char *what() const throw();
	};
	
	class GradeTooHighException: public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);