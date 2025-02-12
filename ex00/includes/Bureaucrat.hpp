/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:07:01 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 12:08:24 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Colors.hpp"

class Bureaucrat {

    public:

        Bureaucrat( void );
        Bureaucrat( Bureaucrat const & src);
        Bureaucrat( std::string const & name, int grade );
  
        ~Bureaucrat();
        
        Bureaucrat &            operator=( Bureaucrat const & other );

        void                    incrementGrade();
		void                    decrementGrade();

		std::string const &     getName() const;
		int const &             getGrade() const;

// ---------------------------------------------------------- Exceptions

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                return "Exception caught: Grade is too high!\n";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                return "Exception caught: Grade is too low!\n";
            }
        };
// ---------------------------------------------------------- Exceptions
    protected:

    private:

        std::string const       _name;
        int                     _grade;
};

std::ostream & operator<<( std::ostream & lhs, Bureaucrat const & rhs );
