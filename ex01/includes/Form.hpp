/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:42:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 12:19:31 by okapshai         ###   ########.fr       */
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
        Form( std::string const & name, int gradeToSign, int gradeToExecute );
        Form( Form const & src );
        
        ~Form();
        
        Form &                  operator=( Form const & other);
        
        std::string const &     getName()           const;
        bool                    getIsSigned()       const;
        int                     getGradeToSign()    const;
        int                     getGradeToExecute() const;

        void                    beSigned( Bureaucrat const & b );

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

    protected:
    
    private:
    
        std::string const       _name;
        bool                    _isSigned;
        int const               _gradeToSign;
        int const               _gradeToExecute;
};

std::ostream & operator<<( std::ostream & lhs, Form const & rhs);
