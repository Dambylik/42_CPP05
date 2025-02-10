/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:08 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 16:33:48 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat b1("Donald", 0);
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat b2("Emmanuel", 151);
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat b3("Olaf", 50);
        std::cout << b3;
        
        b3.incrementGrade();
        std::cout << b3;
       
        b3.decrementGrade();
         std::cout << b3;

        std::cout << "-----------------------------------" << std::endl;

        Form f1("Tax Form", 3, 5);
        Form f2("Export Form", 80, 90);
        Form f3("Top Secret Form", 40, 30);

        std::cout << LYELLOW << "\nInitial Form Status:" << RESET << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        std::cout << MAGENTA << "\nOlaf tries to sign Tax Form:" << RESET << std::endl;
        b3.signForm(f1);

        std::cout << MAGENTA << "Olaf tries to sign Export Form:" << RESET << std::endl;
        b3.signForm(f2);

        std::cout << MAGENTA << "\nOlaf tries to sign Top Secret:" << RESET << std::endl;
        b3.signForm(f3);
        
        std::cout << LYELLOW << "Final Form Status:" << RESET << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        
        std::cout << "-----------------------------------" << std::endl << std::endl;
        
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}

