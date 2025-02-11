/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:23:59 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 13:30:07 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class PresidentialPardonForm : public AForm {
	
	public :
	
		PresidentialPardonForm( std::string const & target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		
		~PresidentialPardonForm();
		
		
		PresidentialPardonForm & 	operator=( PresidentialPardonForm const & other );

		void						execute( Bureaucrat const & executor ) const;

	protected:

		PresidentialPardonForm( void );

	private :
		
		std::string const & 		_target;
};

