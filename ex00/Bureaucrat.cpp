/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:28 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/03 16:48:36 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("undifined"), _grade(0)
{
	std::cout << "Constructor called\n";
}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name)
{
	std::cout << this->_name << " Constructor called\n";
	if (grade > 150)
		throw GradeTooLoHighException();
	else if (grade < 1)
		throw GradeTooLoLowException();
	this->_grade = grade; 
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " destructor called\n";
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

int Bureaucrat::Get_Grade() const
{
	return this->_grade;
}

std::string Bureaucrat::Get_Name() const
{
	return this->_name;
}

const char *Bureaucrat::GradeTooLoLowException::what() const throw()
{
	return "Error grade too low";
}

const char *Bureaucrat::GradeTooLoHighException::what() const throw()
{
	return "Error grade too High";
}

void Bureaucrat::promote()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLoHighException();
	else
		this->_grade++;
}

void Bureaucrat::demote()
{
	if (this->_grade - 1 < 1)
		throw GradeTooLoHighException();
	else
		this->_grade--;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.Get_Name() << " is a bureaucrat with the grade " << b.Get_Grade();
	return os;
}