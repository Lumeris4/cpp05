/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:14:25 by lelanglo          #+#    #+#             */
/*   Updated: 2025/04/01 11:14:52 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string.h>
#include <iostream>
class Bureaucrat;

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

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif