#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public :
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();

	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	
	void execute(const Bureaucrat&) const;

protected:
	RobotomyRequestForm();

private :
	const std::string& _target;
};

#endif // !ROBOTOMYREQUESTFORM_HPP
