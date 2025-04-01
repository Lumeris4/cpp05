/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:10:05 by lelanglo          #+#    #+#             */
/*   Updated: 2025/04/01 11:15:59 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("undifined"), _is_signed(false), _grade_sign(0), _grade_excecute(0)
{
	return;
}

Form::Form(std::string name, int sign, int exec): _name(name), _grade_sign(sign), _grade_excecute(exec)
{
	return;
}

Form::~Form() {};

Form::Form(Form &copy): _name(copy._name), _is_signed(false), _grade_sign(copy._grade_sign), 
						_grade_excecute(copy._grade_excecute) {};

Form &Form::operator=(const Form &other)
{
	if (this != &other) {}
	return *this;
}

int Form::get_exec() const
{
	return this->_grade_excecute;
}

int Form::get_sign() const
{
	return this->_grade_sign;
}

const std::string Form::get_name() const
{
	return this->_name;
}

bool Form::get_is_signed() const
{
	return this->_is_signed;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &b)
{
	os << b.get_name() << " is a Form with the grade " << b.get_sign()
	<< " required for signed and " << b.get_exec() << " required for execute and actually the Form is ";
	if (b.get_is_signed() == false)
		std::cout << "not signed\n";
	else
		std::cout << "signed\n";
	return os;
}

bool Form::be_signed(Bureaucrat &bureau)
{
	if (bureau.Get_Grade() <= this->get_sign())
	{
		this->_is_signed = true;
		return true;
	}
	else
	{
		throw GradeTooLowException();
		return false;
	}
}
