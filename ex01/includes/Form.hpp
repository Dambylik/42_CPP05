/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:42:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 12:42:24 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    
    public:
        
        Form( void );
        Form( std::string const & name, int signGrade, int execGrade );
        Form( Form const & src );
        
        ~Form();
        
        Form &                  operator=( Form const & other);
        
        std::string const &     getName()           const;
        bool                    getStatus()         const;
        int                     getSignGrade()      const;
        int                     getExecuteGrade()   const;

        void                    beSigned( Bureaucrat const & b );

// ---------------------------------------------------------- Exceptions

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Form Exception caught. Grade is too high.\n";
            }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Form Exception caught. Grade is too low.\n";
            }
        };
// ---------------------------------------------------------- Exceptions
    
    protected:
    
    private:
    
        std::string const       _name;
        bool                    _isSigned;
        int const               _signGrade;
        int const               _executeGrade;
};

std::ostream & operator<<( std::ostream & lhs, Form const & rhs);
