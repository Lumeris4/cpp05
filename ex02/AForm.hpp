/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:14:25 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/20 13:20:09 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string.h>
#include <iostream>
class Bureaucrat;

class AForm
{
	private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_excecute;

	protected:
	AForm();
	AForm(std::string name, int sign, int exec);
	AForm(AForm &copy);

	public:
	~AForm();
	AForm &operator=(const AForm &other);
	const std::string get_name() const;
	bool get_is_signed() const;
	int get_sign() const;
	int get_exec() const;
	bool be_signed(Bureaucrat &bureau);
	virtual void execute(Bureaucrat const &executor) const;
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

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif