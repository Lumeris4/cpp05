/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:14:25 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/04 15:56:38 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form
{
	private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_excecute;

	public:
	Form();
	Form(std::string name, int sign, int exec);
	~Form();
	Form(Form &copy);
	Form &operator=(const Form &other);
	const std::string get_name() const;
	bool get_is_signed() const;
	int get_sign() const;
	int get_exec() const;
	bool be_signed(Bureaucrat &bureau);
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
