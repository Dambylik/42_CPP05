/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:08 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/12 12:32:52 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    
    std::cout << "------------------" << std::endl;
    
    try {
        Bureaucrat b1("Donald", 500);
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "------------------" << std::endl;
    
    try {
        Bureaucrat b2("Emmanuel", -42);
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "------------------" << std::endl;

    try {
        Bureaucrat b3("Olaf", 2);
        std::cout << b3 << std::endl;
        
        b3.incrementGrade();
        std::cout << b3 << std::endl;
       
        b3.decrementGrade();
         std::cout << b3 << std::endl;
    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
   
    std::cout << "------------------" << std::endl;

    return (0);
}

