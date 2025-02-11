/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:43:03 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 13:57:07 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ):_name("Empty form"), _isSigned(false), _signGrade(0), _executeGrade(0) {

    std::cout << ORANGE << "Form default constructor called" << RESET << "\n";
}

AForm::AForm( std::string const & name, int gradeToSign, int gradeToExecute ): 
  _name(name), _isSigned(false), _signGrade(gradeToSign), _executeGrade(gradeToExecute) {

std::cout << ORANGE << "AForm base with args constructor called" << RESET
              << "\n";
  
	if (gradeToExecute < 1 || gradeToExecute > 150 || gradeToSign < 1 || gradeToSign > 150 ) {
        
        try {
            if (_executeGrade < 1 || _signGrade < 1)
                throw GradeTooHighException();
            if (_executeGrade > 150 || _signGrade > 150)
                throw GradeTooLowException();
        }
        catch ( std::exception const & e ) {
            std::cerr << e.what() << std::endl;
        }
    }
	return;
}

AForm::AForm( AForm const & src ) : _name(src.getName()), _isSigned(false), 
      _signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()) {

        std::cout << GRAY << "AForm copy constructor called" << RESET<< std::endl;
		(*this) = src;
      }

AForm & AForm::operator=( AForm const & other ) {
    
    std::cout << LYELLOW << "AForm assignment operator called" << RESET << std::endl;
     
    if (this != &other) {
        this->_isSigned = other.getStatus();
    }
    return (*this);
}

std::ostream & operator<<( std::ostream & lhs, AForm const & rhs ) {
	
	if ((rhs.getExecuteGrade() < 1 || rhs.getExecuteGrade() > 150) ||
      (rhs.getSignGrade() < 1 || rhs.getSignGrade() > 150)) {
		
		try {
			if (rhs.getSignGrade() < 1 || rhs.getExecuteGrade() < 1)
				throw "AForm exception caught: Grade is too high!\n";
			if (rhs.getSignGrade() > 150 || rhs.getExecuteGrade() > 150)
				throw "AForm exception caught: Grade is too low!\n";
    	}
		catch (const char *e) {
    		std::cerr << e << std::endl;
    	}
  	} 
	else {
    lhs << "AForm " << LGREEN << rhs.getName() << RESET
        << ", created with a grade of " << LGREEN << rhs.getSignGrade()
        << RESET << ".\n\n";
  	}
	return (lhs);
}
  
AForm::~AForm() {

    std::cout << RED << "AForm destructor called" << RESET << std::endl;
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
