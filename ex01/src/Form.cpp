/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:00:07 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/07 17:04:17 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(Form const &src) 
    : _name(src._name), _isSigned(src._isSigned), 
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

// Assignment Operator
Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string const &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// beSigned Method
void Form::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exception Messages
const char *Form::GradeTooHighException::what() const throw() {
    return "Exception: Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Exception: Form grade is too low!";
}

// Overload << Operator
std::ostream &operator<<(std::ostream &out, Form const &form) {
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}
