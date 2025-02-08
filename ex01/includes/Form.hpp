/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:42:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/08 11:26:21 by okapshai         ###   ########.fr       */
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

    protected:
    
    private:
    
        std::string const       _name;
        bool                    _isSigned;
        int const               _gradeToSign;
        int const               _gradeToExecute;
};

std::ostream & operator<<( std::ostream & lhs, Form const & rhs);
