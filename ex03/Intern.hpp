/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:36:16 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/25 15:03:11 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class AForm;

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &other);
	AForm *makeForm(std::string name, std::string target);
	class FormDoesNotExist: public std::exception
	{
		public:
		const char *what() const throw();
	};
};