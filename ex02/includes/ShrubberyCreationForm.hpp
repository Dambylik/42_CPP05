/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:23:02 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 18:26:07 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    
    public :
        ShrubberyCreationForm( std::string const & target );
        ShrubberyCreationForm( const ShrubberyCreationForm & src );
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=( const ShrubberyCreationForm & other );
        void action() const;
};

