/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:09:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 12:49:14 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ): _name("Bubu"), _grade(0) {

    std::cout << GREEN << "Bureaucrat default constructor called" << RESET<< std::endl;
    return;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name) {
	
    std::cout << GREEN << "Bureaucrat string-int constructor called" << RESET << std::endl;
    
	if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
	
	else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
	else 
        this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ): _name(src.getName()), _grade(src.getGrade()) {

    std::cout << GRAY << "Bureaucrat copy constructor called" << RESET<< std::endl;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & other ) {

    std::cout << LYELLOW << "Bureaucrat assignment operator called" << RESET << std::endl;

    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::ostream & operator<<( std::ostream & lhs, Bureaucrat const & rhs) {

    lhs << LGREEN << rhs.getName() << RESET << ", bureaucrat grade " << LGREEN << rhs.getGrade()<< ".\n" << RESET;
    return (lhs);
}

Bureaucrat::~Bureaucrat() {

    std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}


// ---------------------------------------------------------- Methods

void Bureaucrat::incrementGrade() {

  if (this->_grade - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  }

  this->_grade--;
}

void Bureaucrat::decrementGrade() {

  if (this->_grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  }

  this->_grade++;
}

void Bureaucrat::signForm( Form & form ) {
    
    try {      
        form.beSigned(*this);
        std::cout << LGREEN << this->getName() << RESET << " signed " << LGREEN 
                << form.getName() << RESET << std::endl;
    }
    catch ( Form::GradeTooLowException const & e ) {
        std::cerr <<  LMAGENTA << this->getName() << RESET << " couldn’t sign " << form.getName() 
                  << " because " << LMAGENTA << e.what() << RESET << std::endl;
    }
}


// ---------------------------------------------------------- Setters & Getters

std::string const & Bureaucrat::getName() const { return this->_name; }
int const & Bureaucrat::getGrade() const { return this->_grade; }