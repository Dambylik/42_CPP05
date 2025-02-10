/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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


class AForm {
    
    public:
        
        AForm();
        AForm( std::string const & name, int signGrade, int execGrade, std::string const & target );
        AForm( AForm const & src );
        virtual ~AForm();
        
        AForm &                 operator=( AForm const & other);
        
        std::string const &     getName() const;
        bool                    getStatus() const;
        int                     getSignGrade() const;
        int                     getExecuteGrade() const;
        std::string const &     getTarget() const;

        void                    beSigned( Bureaucrat const & b );
        void                    execute( Bureaucrat const & executor ) const;

        virtual void            action() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "AForm Exception caught. Grade is too high.";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "AForm Exception caught. Grade is too low.";
                }
        };

        class UnsignedFormException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "AForm Exception caught. The form is not signed.";
                }
        };

    private:
        std::string const       _name;
        bool                    _isSigned;
        int const               _signGrade;
        int const               _executeGrade;
        std::string             _target;
};

std::ostream & operator<<( std::ostream & lhs, AForm const & rhs);

