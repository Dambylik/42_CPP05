#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
public:
	AForm(const std::string &, int, int);
	~AForm();

	AForm(const AForm &);
	AForm &operator=(const AForm &);

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

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(const Bureaucrat&);
	virtual void execute(Bureaucrat const& executioner) const = 0;

protected:
	AForm();

private:
	const std::string name_;
	bool isSigned_;
	const int gradeToSign_;
	const int gradeToExec_;
};

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);

#endif // !AFORM_HPP