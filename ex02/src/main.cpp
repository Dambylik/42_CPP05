/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:08 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 18:38:58 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Alice", 1);
        Bureaucrat intern("Bob", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        intern.signForm(shrub);
        boss.executeForm(shrub);

        boss.signForm(robo);
        boss.executeForm(robo);

        boss.signForm(pardon);
        boss.executeForm(pardon);
    } 
    
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

