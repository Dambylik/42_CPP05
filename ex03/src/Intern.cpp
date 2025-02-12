/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:45:26 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 15:55:29 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {

    std::cout << LBLUE << "Intern default constructor called" << RESET << std::endl;
    return;
}

Intern::Intern( Intern const & src ) {

    std::cout << LBLUE << "Intern copy constructor called" << RESET << std::endl;
	(*this) = src;
}

Intern &	Intern::operator=( Intern const & other) {

    std::cout << LBLUE << "Intern assignment operator called" << RESET << std::endl;
    (void) other;
	return (*this);
}

Intern::~Intern() {

    std::cout << LBLUE << "Intern default destructor called" << RESET << std::endl;
}

// ---------------------------------------------------------- Methods

AForm*	Intern::makeForm( std::string name, std::string target )
{
	try {
		std::string form[] = {
			"Robotomy",
			"Presidential Pardon",
			"Shrubbery Creation"
		};

		AForm* forms[] = {
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target),
			new ShrubberyCreationForm(target)
		};

		for (int i = 0; i < 3; i++) {
			if (name == form[i]) {
				std::cout << LBLUE << "Intern" << RESET << " creates " << name << std::endl;
				for (int i = 0; i < 3; i++) {
					if (name != form[i]) {
		                std::cout << LBLUE << "Intern" << RESET << " couldn't create " << name << std::endl;
						AForm* badForm = forms[i];
						delete badForm;
					}
				}
				return (forms[i]);
			}
		}

		std::cout << "Intern couldn't create " << name << std::endl;
		for (int i = 0; i < 3; i++) {
			AForm* badForm = forms[i];
			delete badForm;
		}
		return (NULL);

	}
    catch( std::bad_alloc const & e) {
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	return (NULL);
}