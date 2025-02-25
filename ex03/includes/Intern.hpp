/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:44:52 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/13 10:12:48 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
    
    public:
        
        Intern( void );
        Intern( std::string const & target );
		Intern( Intern const & src );
        
        ~Intern();

        Intern & 	operator=( Intern const & other );

        AForm*	    makeForm( std::string formName, std::string target );

    protected:

	private :
};
