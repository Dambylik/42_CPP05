#include "RobotomyRequestForm.hpp"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Args Constructor
// ----------------------------------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
					: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	if (DEBUG)
		std::cout << YELLOW << "Robotomy request form arguments constructor called"
				  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Copy Constructor
// ----------------------------------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
					: AForm(rhs), _target(rhs._target) {
  if (DEBUG)
    std::cout << YELLOW << "Robotomy request form copy constructor called"
			  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- Destructor
// ----------------------------------------------------------------------------
RobotomyRequestForm::~RobotomyRequestForm() {
	if (DEBUG)
		std::cout << YELLOW << "Robotomy request form base destructor called"
				  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- Overload
// ----------------------------------------------------------------------------
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
  if (DEBUG)
    std::cout << YELLOW << "Robotomy request form base assignment operator Called"
			  << RESET << std::endl;

	(void)rhs;

	return (*this);
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- Methods
// ----------------------------------------------------------------------------
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {

	if (this->getIsSigned() == false)
		throw(AForm::UnsignedFormException());
	else if(executor.getGrade() > this->getGradeToExec())
		throw(AForm::GradeTooLowException());
	
	srand(time(NULL));
	int r = rand() % 100 + 1;
	if (r > 50)
		std::cout << this->_target << " has successfully been ROBOTOMIZED" << std::endl;
	else
		std::cout << this->_target << " has NOT been ROBOTOMIZED" << std::endl;
}