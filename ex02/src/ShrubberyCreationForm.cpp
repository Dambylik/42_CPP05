/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:10:29 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 14:05:31 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137), _target("tree") {

	std::cout << CYAN << "ShrubberyCreationForm string constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target )
					  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

	std::cout << CYAN << "ShrubberyCreationForm string constructor called"
				  << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src)
					  : AForm(src), _target(src._target) {

    std::cout << CYAN << "ShrubberyCreationForm copy constructor called"
				  << RESET << std::endl;
	return;			  
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other ) {

    std::cout << CYAN << "ShrubberyCreationFormassignment operator called"
				  << RESET << std::endl;
	if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    
	std::cout << CYAN << "ShrubberyCreationForm destructor called"
				  << RESET << std::endl;
}


// ---------------------------------------------------------- Methods

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getStatus() == false)
		throw(AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw(AForm::GradeTooLowException());

	std::string l = this->_target + "_shrubbery";
	const char* p = l.c_str();
	std::ofstream file(p, std::ios_base::app);
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||       " << std::endl;
    file << "      ||       " << std::endl;
    file << "      ||       " << std::endl;

    file.close();
}
