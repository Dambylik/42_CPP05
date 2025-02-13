/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:04:14 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/13 11:07:48 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequest", 72, 45), _target("default") {
	
    std::cout << BLUE << "Bureaucrat default constructor called" << RESET<< std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target )
					: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	
    std::cout << BLUE << "RobotomyRequestForm string constructor called" << RESET<< std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
					: AForm(src), _target(src._target) {
	
	std::cout << BLUE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm() {

	std::cout << BLUE << "RobotomyRequestForm default destructor called"
				  << RESET << std::endl;
}


RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & other) {

    std::cout << BLUE << "RobotomyRequestFormbase assignment operator called"
			  << RESET << std::endl;
	if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
	return (*this);
}

// ---------------------------------------------------------- Methods

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {

	if (this->getStatus() == false)
		throw(AForm::UnsignedFormException());
	else if(executor.getGrade() > this->getExecuteGrade())
		throw(AForm::GradeTooLowException());
	
	srand(time(NULL));
	int r = rand() % 100 + 1;
	if (r > 50)
		std::cout << GREEN << "YOUPEEEYYY !!! " <<this->_target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << LRED << "ZZZZZ !!! "<< this->_target << "'s robotomy failed" << RESET << std::endl;
}