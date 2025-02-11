#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <exception>


class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error Occured!\nGrade too high.\n";
    }
};

class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error Occured!\nGrade too low.\n";
    }
};

class UnsignedFormException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error Occured!\nGrade too low.\n";
    }
};


#endif // !EXCEPTIONS_HPP
