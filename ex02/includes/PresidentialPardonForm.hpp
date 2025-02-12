/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:23:59 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 13:59:09 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class PresidentialPardonForm : public AForm {
	
	public :

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const & target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		
		virtual ~PresidentialPardonForm();
		
		
		PresidentialPardonForm & 	operator=( PresidentialPardonForm const & other );

		void						execute( Bureaucrat const & executor ) const;

	protected:

	private :
		
		std::string 	 			_target;
};

