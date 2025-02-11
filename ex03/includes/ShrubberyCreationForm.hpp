/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:29:37 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 14:16:24 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	
	public :
	
		ShrubberyCreationForm( std::string const & target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		
		~ShrubberyCreationForm();
		
		
		ShrubberyCreationForm & 	operator=( ShrubberyCreationForm const & other );

		void						execute( Bureaucrat const & executor ) const;

	protected:

		ShrubberyCreationForm( void );

	private :
		
		std::string const & 		_target;
};