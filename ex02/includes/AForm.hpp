/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:15 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 13:30:05 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
	
	public:
	
		AForm( std::string const & name, int signGrade, int execGrade );
		AForm( AForm const & src );
		
		~AForm();

		AForm &                  operator=( AForm const & other);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "AForm exception caught: Grade is too high!\n";
			}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "AForm exception caught: Grade is too low!\n";
			}
		};

		class UnsignedFormException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "AForm exception caught: Grade is too low!\n";
			}
		};

		std::string const &     getName() 			const;
		bool 					getStatus() 		const;
		int 					getSignGrade() 		const;
		int 					getExecuteGrade() 	const;

		void 					beSigned( Bureaucrat const & b);
		virtual void 			execute( Bureaucrat const & executioner ) const = 0;

	protected:
		
		AForm( void );

	private:
		const std::string 		_name;
		bool 					_isSigned;
		
		int const 				_signGrade;
		int const 				_executeGrade;
};

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);
