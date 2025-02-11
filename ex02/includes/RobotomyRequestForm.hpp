/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:28:15 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 14:09:46 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm {
	
	public :
	
		RobotomyRequestForm( std::string const & target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		
		~RobotomyRequestForm();
		
		
		RobotomyRequestForm & 		operator=( RobotomyRequestForm const & other );

		void						execute( Bureaucrat const & executor ) const;

	protected:

		RobotomyRequestForm( void );

	private :
		
		std::string const & 		_target;
};
