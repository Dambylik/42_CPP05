/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:08 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/08 12:02:34 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    
    try {
        Bureaucrat b1("Donald", 2);
        Bureaucrat b2("Emmanuel", 150);

        Form f1("Tax Form", 3, 5);
        Form f2("Top Secret Form", 1, 1);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << "\nDonald tries to sign Tax Form:" << std::endl;
        b1.signForm(f1);  // Should succeed

        std::cout << "\nEmmanuel tries to sign Top Secret Form:" << std::endl;
        b2.signForm(f2);  // Should fail

        std::cout << "\nFinal Form Status:" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } 
    catch ( const std::exception & e ) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
