/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:57:35 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 14:05:21 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5), _target("Bubu") {
        
    std::cout << MAGENTA << "PresidentialPardonForm string constructor called" << RESET << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ): 
                        AForm("PresidentialPardonForm", 25, 5), _target(target) {
        
    std::cout << MAGENTA << "PresidentialPardonForm string constructor called"
                  << RESET << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
					   : AForm(src), _target(src._target) {

    std::cout << MAGENTA << "PresidentialPardonForm copy constructor called"
                  << RESET << std::endl;
    return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & other)
{
    std::cout << MAGENTA << "PresidentialPardonForm assignment operator called"
                  << RESET << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

    std::cout << MAGENTA << "PresidentialPardonForm destructor called"
                  << RESET << std::endl;
}

// ---------------------------------------------------------- Methods

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {

	if (this->getStatus() == false)
		throw(AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw(AForm::GradeTooLowException());
		
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}