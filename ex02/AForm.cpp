/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:10:05 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/31 14:08:09 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("undifined"), _is_signed(false), _grade_sign(0), _grade_excecute(0)
{
	return;
}

AForm::AForm(std::string name, int sign, int exec): _name(name), _is_signed(false) ,_grade_sign(sign), _grade_excecute(exec)
{
	return;
}

AForm::~AForm() {};

AForm::AForm(AForm &copy): _name(copy._name), _is_signed(false), _grade_sign(copy._grade_sign), 
						_grade_excecute(copy._grade_excecute) {};

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other) {}
	return *this;
}

int AForm::get_exec() const
{
	return this->_grade_excecute;
}

int AForm::get_sign() const
{
	return this->_grade_sign;
}

const std::string AForm::get_name() const
{
	return this->_name;
}

bool AForm::get_is_signed() const
{
	return this->_is_signed;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &b)
{
	os << b.get_name() << " is a Form with the grade " << b.get_is_signed()
	<< " required for signed and " << b.get_exec() << " required for execute and actually the Form is ";
	if (b.get_is_signed() == false)
		std::cout << " not signed\n";
	else
		std::cout << " signed\n";
	return os;
}

bool AForm::be_signed(Bureaucrat &bureau)
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

void AForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor.Get_Name() << "execute nothing !\n";
}
