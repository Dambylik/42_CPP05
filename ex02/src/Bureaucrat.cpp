/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:30:54 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 13:42:08 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Bubu"), _grade(0) {

    std::cout << GREEN << "Bureaucrat default constructor called" << RESET<< std::endl;
    return;
}


Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name) {

	std::cout << GREEN << "Bureaucrat string-int constructor called" << RESET << std::endl;

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

    std::cout << LYELLOW << "Bureaucrat assignment operator called" << RESET << std::endl;

    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::ostream & operator<<( std::ostream & lhs, Bureaucrat const & rhs) {

    lhs << rhs.getName() << ", bureaucrat grade " << LGREEN << rhs.getGrade()<< ".\n" << RESET;
    return (lhs);
}


Bureaucrat::~Bureaucrat() {

    std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
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
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch ( std::exception const & e ) {
        std::cerr << this->getName() << " couldn’t sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::execForm( AForm & form ) {
	
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch( std::exception const & e ) {
		std::cerr << this->getName() << " couldn't execute " << form.getName() 
					<< " because " << e.what() << std::endl;
	}
}

// ---------------------------------------------------------- Setters & Getters

std::string const & Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

