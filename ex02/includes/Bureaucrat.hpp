/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:07:01 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 18:30:16 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Colors.hpp"

class AForm;

class Bureaucrat {
    
    public:

        Bureaucrat();
        Bureaucrat( std::string const & name, int grade );
        Bureaucrat( const Bureaucrat & src );
        ~Bureaucrat();

        Bureaucrat & operator=( const Bureaucrat & other );

        // Getters
        std::string const & getName() const;
        int getGrade() const;

        // Methods
        void incrementGrade();
        void decrementGrade();
        void signForm( AForm & form ) const;
        void executeForm( AForm const & form ) const;

        // Exception Classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Bureaucrat Exception: Grade is too high.";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Bureaucrat Exception: Grade is too low.";
                }
        };

    private:
        const std::string _name;
        int _grade;
};

// Overload of << operator for easy display
std::ostream & operator<<( std::ostream & os, Bureaucrat const & bureaucrat );
