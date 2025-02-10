/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:20:59 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 18:26:13 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    
    public :
        PresidentialPardonForm( std::string const & target );
        PresidentialPardonForm( const PresidentialPardonForm & src );
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=( const PresidentialPardonForm & other );
        void action() const;
};

