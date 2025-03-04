/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:10:05 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/04 14:26:55 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(): _name("undifined"), _is_signed(false), _grade_sign(0), _grade_excecute(0)
{
	return;
}

Form::Form(std::string name, int sign, int exec): _name(name), _grade_sign(sign), _grade_excecute(exec)
{
	return;
}

Form::~Form() {};

Form::Form(Form &copy): _name(copy._name), _grade_excecute(copy._grade_excecute),
						_grade_sign(copy._grade_sign), _is_signed(false) {}

Form &Form::operator=(const Form &other)
{
	return *this;
}

