/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:22:23 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 18:26:10 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    
    public :
        RobotomyRequestForm( std::string const & target );
        RobotomyRequestForm( const RobotomyRequestForm & src );
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=( const RobotomyRequestForm & other );
        void action() const;
};

