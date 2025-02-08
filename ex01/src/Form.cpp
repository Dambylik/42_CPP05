/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:00:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/08 11:59:49 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form::Form( void ) {

//     std::cout << GREEN << "Form default constructor called" << RESET<< std::endl;
//     return;
// }

Form::Form( std::string const & name, int gradeToSign, int gradeToExecute ) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    
    if (gradeToSign < 1 || gradeToExecute < 1) {
        std::cout << BLUE << "Constructor failed: Grade too high!" << RESET << std::endl;
        throw GradeTooHighException();
    }
        
    if (gradeToSign > 150 || gradeToExecute > 150) {
        std::cout << BLUE << "Constructor failed: Grade too low!" << RESET << std::endl;
        throw GradeTooLowException();
    }
    return;
}

Form::Form( Form const & src ) : _name(src._name), _isSigned(src._isSigned), 
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {

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
    lhs << "Form " << rhs.getName() 
        << ", signed: " << (rhs.getIsSigned() ? "Yes" : "No")
        << ", grade required to sign: " << rhs.getGradeToSign()
        << ", grade required to execute: " << rhs.getGradeToExecute();
    return (lhs);
}

Form::~Form() {

    std::cout << RED << "Form destructor called" << RESET << std::endl;
}


// ---------------------------------------------------------- Methods

void Form::beSigned( Bureaucrat const & b ) {
    
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// ---------------------------------------------------------- Setters & Getters

std::string const & Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }