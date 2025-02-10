/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:00:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 16:49:21 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( std::string const & name, int gradeToSign, int gradeToExecute ) 
    : _name(name), _isSigned(false), _signGrade(gradeToSign), _executeGrade(gradeToExecute) {
    
    std::cout << GREEN << "Form string-int constructor called" << RESET << std::endl;
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
        
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    return;
}

Form::Form( Form const & src ) : _name(src._name), _isSigned(src._isSigned), 
      _signGrade(src._signGrade), _executeGrade(src._executeGrade) {

        std::cout << GRAY << "Form copy constructor called" << RESET<< std::endl;
      }

Form & Form::operator=( Form const & other ) {
    
    std::cout << LYELLOW << "Form assignment operator called" << RESET << std::endl;
     
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

std::ostream & operator<<( std::ostream & lhs, Form const & rhs) {
    lhs << rhs.getName() << " signed? ";
        if (rhs.getStatus())
            lhs << GREEN "YES" << RESET;
        else 
            lhs << RED << "NO" << RESET;
    lhs << ". Grade required to sign: " << LGREEN << rhs.getSignGrade() << RESET
        << ". Grade required to execute: " << LGREEN << rhs.getExecuteGrade() << RESET;

    return (lhs);
}

Form::~Form() {

    std::cout << RED << "Form destructor called" << RESET << std::endl;
}

// ---------------------------------------------------------- Methods

void Form::beSigned( Bureaucrat const & b ) {
    
    if (b.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// ---------------------------------------------------------- Setters & Getters

std::string const & Form::getName() const { return _name; }
bool Form::getStatus() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecuteGrade() const { return _executeGrade; }

