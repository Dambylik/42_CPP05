/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:10:08 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 16:38:40 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    
    std::cout << "------------------" << std::endl;
    
    try {
        Bureaucrat a("Donald", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------------" << std::endl;

    try {
        Bureaucrat b("Emmanuel", 149);
        std::cout << b << std::endl;

        b.decrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
