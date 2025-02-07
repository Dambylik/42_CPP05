/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:42:45 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 17:07:01 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    // Constructors & Destructor
    Form(std::string const &name, int gradeToSign, int gradeToExecute);
    Form(Form const &src);
    Form &operator=(Form const &rhs);
    ~Form();

    // Getters
    std::string const &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Methods
    void beSigned(Bureaucrat const &b);

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExecute;
};

// Overload << operator
std::ostream &operator<<(std::ostream &out, Form const &form);
