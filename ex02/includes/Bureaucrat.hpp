#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include "Colors.hpp"
#include <iostream>
#include <string>

#define DEBUG 0

#define SUCCESS 0
#define ERROR 1

class AForm;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string &, int);
	~Bureaucrat();

	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(const Bureaucrat &);

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

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm&);
	void execForm(AForm&);

	const std::string getName() const;
	int getGrade() const;

private:
	const std::string name_;
	int grade_;
};

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif // !BUREAUCRAT_HPP