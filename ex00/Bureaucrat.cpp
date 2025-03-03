/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:28 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/03 16:32:35 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("undifined"), _grade(0)
{
	std::cout << "Constructor called\n";
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string name): _name(name)
{
	std::cout << this->_name << "Constructor called\n";
	if (grade > 150)
		throw GradeTooLoHighException();
	else if (grade < 1)
		throw GradeTooLoLowException();
	this->_grade = grade; 
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << "destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other._grade;
	return *this;
}

unsigned int Bureaucrat::Get_Grade()
{
	return this->_grade;
}

std::string Bureaucrat::Get_Name()
{
	return this->_name;
}

const char *Bureaucrat::GradeTooLoLowException::what() const throw()
{
	return "Error grade too low\n";
}

const char *Bureaucrat::GradeTooLoHighException::what() const throw()
{
	return "Error grade too High\n";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.Get_Name() << "is a bureaucrat with the grade" << b.Get_Grade() << std::endl;
}