/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:59:32 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/20 14:53:31 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string target;
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	const std::string getTarget() const;
	class IsNotSigned: public std::exception
	{
		public:
		const char *what() const throw();
	};
	void execute(Bureaucrat const &executor) const;
};