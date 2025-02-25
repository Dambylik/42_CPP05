/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:45:26 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/25 13:34:36 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {

    std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
    return;
}

Intern::Intern( Intern const & src ) {

    std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
	(void) src;
	return;
}

Intern &	Intern::operator=( Intern const & other) {

    std::cout << GREEN << "Intern assignment operator called" << RESET << std::endl;
    (void) other;
	return (*this);
}

Intern::~Intern() {

    std::cout << GREEN << "Intern default destructor called" << RESET << std::endl;
}

// ---------------------------------------------------------- Methods

AForm* createRobotomy(const std::string& t) {
    return new RobotomyRequestForm(t);
}

AForm* createPresidentialPardon(const std::string& t) {
    return new PresidentialPardonForm(t);
}

AForm* createShrubberyCreation(const std::string& t) {
    return new ShrubberyCreationForm(t);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    
    std::string formTypes[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery"
    };

    AForm* (*formCreators[3])(const std::string&) = {
        createRobotomy,
        createPresidentialPardon,
        createShrubberyCreation
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            try {
                AForm* form = formCreators[i](target);
                std::cout << "Intern creates " << formName << std::endl;
                return form;
            }
            catch (const std::exception& e) {
                std::cerr << "Error: Failed to create form '" << formName << "': " << e.what() << std::endl;
                return NULL;
            }
        }
    }
    std::cout << RED << "Error: Intern couldn't create form '" << formName << "'" << RESET << std::endl;
    return NULL;
}
