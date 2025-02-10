/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:08 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 13:36:12 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    
    std::cout << "------------------" << std::endl;
    
    try {
        Bureaucrat a("Donald", 500);
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "------------------" << std::endl;
    
    try {
        Bureaucrat b("Emmanuel", -42);
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "------------------" << std::endl;

    try {
        Bureaucrat c("Olaf", 2);
        std::cout << c << std::endl;
        
        c.incrementGrade();
        std::cout << c << std::endl;
       
        c.decrementGrade();
         std::cout << c << std::endl;
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
   
    std::cout << "------------------" << std::endl;

    return 0;
}
