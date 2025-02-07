/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:07:01 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 17:08:07 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Colors.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat {

    public:

        Bureaucrat( void );
        Bureaucrat( Bureaucrat const & src);
        Bureaucrat( std::string const & name, int grade );
  
        ~Bureaucrat();
        
        Bureaucrat &            operator=( Bureaucrat const & other );

        void                    incrementGrade();
		void                    decrementGrade();
        void                    signForm(Form &form);
		int                     isGradeOutOfRange( int i );

		std::string const &     getName() const;
		int const &    getGrade() const;

    protected:

    private:

        std::string const       _name;
        int            _grade;
};

std::ostream & operator<<( std::ostream & lhs, Bureaucrat const & rhs );
