#include "PresidentialPardonForm.hpp"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Args Constructor
// ----------------------------------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
					   : AForm("PresidentialPardonForm", 25, 5), target_(target) {
    if (DEBUG)
        std::cout << MAGENTA << "PresidentialPardonForm args derived constructor called"
                  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Copy Constructor
// ----------------------------------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
					   : AForm(rhs), target_(rhs.target_) {
    if (DEBUG)
        std::cout << MAGENTA << "PresidentialPardonForm derived copy constructor called"
                  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- Destructor
// ----------------------------------------------------------------------------
PresidentialPardonForm::~PresidentialPardonForm() {
    if (DEBUG)
        std::cout << MAGENTA << "PresidentialPardonForm derived destructor called"
                  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- Overload
// ----------------------------------------------------------------------------
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    std::cout << MAGENTA << "PresidentialPardonForm assignment copy operator called"
                  << RESET << std::endl;
    (void)rhs;

	return (*this);
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- Methods
// ----------------------------------------------------------------------------
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {

	if (this->getIsSigned() == false)
		throw(AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw(AForm::GradeTooLowException());
		
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}