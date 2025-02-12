/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:28:15 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 13:56:30 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm {
	
	public :
	
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const & target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		
		virtual ~RobotomyRequestForm();
		
		
		RobotomyRequestForm & 		operator=( RobotomyRequestForm const & other );

		void						execute( Bureaucrat const & executor ) const;

	protected:

	private :
		
		std::string 				_target;
};
