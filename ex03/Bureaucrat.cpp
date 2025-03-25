/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:28 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/25 15:20:59 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("undifined"), _grade(0)
{
	std::cout << "Constructor called\n";
}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name)
{
	std::cout << this->_name << " Constructor called\n";
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
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

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error grade too High";
}

void Bureaucrat::promote()
{
	if (this->_grade + 1 > 150)
		throw GradeTooHighException();
	else
		this->_grade++;
}

void Bureaucrat::demote()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::signForm(AForm &lala)
{
	try
	{
		if (lala.be_signed(*this) == true)
			std::cout << this->_name << " signed " << lala.get_name() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << lala.get_name()
					<< " Because " << e.what() << std::endl;
	}				
}

void Bureaucrat::execute(AForm const &form)
{
	form.execute(*this);
	std::cout << this->Get_Name() << " executed " << form.get_name() << "\n";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.Get_Name() << " is a bureaucrat with the grade " << b.Get_Grade();
	return os;
}