/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:26:58 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/20 14:27:16 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
	private:
		const std::string target;
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	const std::string getTarget() const;
	class IsNotSigned: public std::exception
	{
		public:
		const char *what() const throw();
	};
	void execute(Bureaucrat const &executor) const;
};