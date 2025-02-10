/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:29:32 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 17:20:27 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <iostream>

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
            return "Error Occured: Grade is too low.\n";
    }
};
