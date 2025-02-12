/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:43:03 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 14:02:05 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ):_name("Empty form"), _isSigned(false), _signGrade(0), _executeGrade(0) {

    std::cout << ORANGE << "AForm default constructor called" << RESET << "\n";
}

AForm::AForm( std::string const & name, int gradeToSign, int gradeToExecute ): 
  _name(name), _isSigned(false), _signGrade(gradeToSign), _executeGrade(gradeToExecute) {

    std::cout << ORANGE << "AForm string-int constructor called" << RESET << "\n";
      
    if (_executeGrade < 1 || _signGrade < 1)
        throw AForm::GradeTooHighException();
    if (_executeGrade > 150 || _signGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const & src ) : _name(src.getName()), _isSigned(false), 
      _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) {

        std::cout << ORANGE << "AForm copy constructor called" << RESET<< std::endl;
		(*this) = src;
      }

AForm & AForm::operator=( AForm const & other ) {
    
    std::cout << ORANGE << "AForm assignment operator called" << RESET << std::endl;
     
    if (this != &other) {
        this->_isSigned = other.getStatus();
    }
    return (*this);
}

std::ostream & operator<<( std::ostream & lhs, AForm const & rhs ) {
	
	if ((rhs.getExecuteGrade() < 1 || rhs.getExecuteGrade() > 150) ||
      (rhs.getSignGrade() < 1 || rhs.getSignGrade() > 150)) {
		
	    if (rhs.getSignGrade() < 1 || rhs.getExecuteGrade() < 1)
				throw AForm::GradeTooHighException();
		if (rhs.getSignGrade() > 150 || rhs.getExecuteGrade() > 150)
				throw AForm::GradeTooLowException();
    }
	else {
        lhs << YELLOW << rhs.getName() << RESET
        << " created, required grade to sign: " << YELLOW << rhs.getSignGrade()
        << RESET << " required grade to execute: " << YELLOW 
        << rhs.getExecuteGrade() << RESET << ".\n\n";     
    }
	return (lhs);
}
  
AForm::~AForm() {

    std::cout << ORANGE << "AForm destructor called" << RESET << std::endl;
}

// ---------------------------------------------------------- Methods

void AForm::beSigned( Bureaucrat const & b ) {
	if (b.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw(Bureaucrat::GradeTooLowException());
}

// ---------------------------------------------------------- Setters & Getters

std::string const & AForm::getName() const { return this->_name; }
bool AForm::getStatus() const { return this->_isSigned; } 
int AForm::getSignGrade() const { return (this->_signGrade); }
int	AForm::getExecuteGrade() const { return (this->_executeGrade); }
