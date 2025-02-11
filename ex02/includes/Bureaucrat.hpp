/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:06:52 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 13:13:20 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	
	public:
	
		Bureaucrat();
		Bureaucrat( Bureaucrat const & src);
		Bureaucrat( std::string const & name, int grade );
		
		~Bureaucrat();
		
		Bureaucrat &            operator=( Bureaucrat const & other );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Bureaucrat exception caught: Grade is too high!\n";
			}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Bureaucrat exception caught: Grade is too low!\n";
			}
		};

		void 					incrementGrade();
		void 					decrementGrade();

		void 					signForm( AForm & form );
		void 					execForm( AForm & form );

		std::string const &     getName() const;
		int 					getGrade() const;

	protected:
	
	private:
	
		std::string const       _name;
        int                     _grade;
};

std::ostream & operator<<(std::ostream & lhs, const Bureaucrat & rhs);
