/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:22:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/11 13:23:40 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>


class GradeTooHighException : public std::exception {
    
    public:
        
        virtual const char* what() const throw() {
            return "Exception caught: Grade is too high!.\n";
    }
};

class GradeTooLowException : public std::exception {
    
    public:
    
        virtual const char* what() const throw() {
            return "Exception caught: Grade is too low!\n";
    }
};

class UnsignedFormException : public std::exception {
    
    public:
    
        virtual const char* what() const throw() {
            return "Exception caught: Grade is too low!\n";
    }
};