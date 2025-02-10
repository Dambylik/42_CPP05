/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:09:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 17:01:08 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("Bubu"), _grade(0) {

    std::cout << GREEN << "Bureaucrat default constructor called" << RESET<< std::endl;
    return;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name) {
	
    std::cout << GREEN << "Bureaucrat string-int constructor called" << RESET << std::endl;
    
	if (grade < 1)
        throw GradeTooHighException();
		
	else if (grade > 150)
            throw GradeTooLowException();
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
  else
  	this->_grade--;
}

void Bureaucrat::decrementGrade() {

  if (this->_grade + 1 > 150) {
    throw GradeTooLowException();
  }
  else
  	this->_grade++;
}

// ---------------------------------------------------------- Setters & Getters

std::string const & Bureaucrat::getName() const { return this->_name; }
int const & Bureaucrat::getGrade() const { return this->_grade; }