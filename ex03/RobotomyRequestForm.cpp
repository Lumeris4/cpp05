/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:26:54 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/31 13:38:36 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("nothing") {};

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 25, 5), target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): AForm(copy) {};

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	(void)other;
	return (*this);
}

const char *RobotomyRequestForm::IsNotSigned::what() const throw()
{
	return ("Form not signed");
}

const std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::srand(std::time(0));

    int random = std::rand() % 2;
    if (this->get_is_signed() == false)
        throw IsNotSigned();
    else if (executor.Get_Grade() > this->get_exec())
        throw GradeTooLowException();
    else
    {
        if (random == 0)
            std::cout << this->getTarget() << " has been robotomized successfully\n";
        else
            std::cout << this->getTarget() << " failed to be robotomized\n";
    }
}
