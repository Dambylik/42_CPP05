/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:30:54 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 18:07:52 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Bubu"), _grade(0) {

    std::cout << GRAY << "Bureaucrat default constructor called" << RESET<< std::endl;
    return;
}


Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name) {

	std::cout << GRAY << "Bureaucrat string-int constructor called" << RESET << std::endl;

    if (grade < 1 || grade > 150)
    {
        try {
            if (grade < 1)
                throw GradeTooHighException();
            if (grade > 150)
                throw GradeTooLowException();
        }
		catch ( std::exception const & e ) {
                std::cerr << e.what() << std::endl;
            }
        }
        else
            this->_grade = grade;
    }

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {

    std::cout << GRAY << "Bureaucrat copy constructor called" << RESET<< std::endl;
	(*this) = src;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & other ) {

    std::cout << GRAY << "Bureaucrat assignment operator called" << RESET << std::endl;

    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::ostream & operator<<( std::ostream & lhs, Bureaucrat const & rhs) {

    lhs << LMAGENTA << rhs.getName() << RESET << ", bureaucrat grade " << LMAGENTA << rhs.getGrade()<< ".\n" << RESET;
    return (lhs);
}


Bureaucrat::~Bureaucrat() {

    std::cout << GRAY << "Bureaucrat destructor called" << RESET << std::endl;
}

// ---------------------------------------------------------- Methods

void Bureaucrat::incrementGrade() {

  if (this->_grade - 1 < 1) {
    throw GradeTooHighException();
  }

  this->_grade--;
}

void Bureaucrat::decrementGrade() {

  if (this->_grade + 1 > 150) {
    throw GradeTooLowException();
  }

  this->_grade++;
}

void Bureaucrat::signForm( AForm & form ) {
    
    try {      
        form.beSigned(*this);
        std::cout << LGREEN << this->getName() << RESET << " signed " << LGREEN 
                << form.getName() << RESET << std::endl;
    }
    catch ( std::exception const & e ) {
        std::cerr <<  LMAGENTA << this->getName() << RESET << " couldn’t sign " << form.getName() 
                  << " because " << LMAGENTA << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::execForm( AForm & form ) {
	
	try {
		form.execute(*this);
		std::cout  << LGREEN << this->getName() << RESET << " executed " << LGREEN << form.getName() << RESET << std::endl;
	}
	catch( std::exception const & e ) {
		std::cerr << LMAGENTA << this->getName() << RESET << " couldn't execute " << form.getName() 
					<< " because " << LMAGENTA << e.what() << RESET << std::endl;
	}
}

// ---------------------------------------------------------- Setters & Getters

std::string const & Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

