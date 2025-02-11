#include "Bureaucrat.hpp"

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------- Constructor
// ----------------------------------------------------------------------------
Bureaucrat::Bureaucrat() : name_("Name undefined"), grade_(10) {
  if (DEBUG)
    std::cout << GREEN << "Bureaucrat Base Constructor called" << RESET
              << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Args Constructor
// ----------------------------------------------------------------------------
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
  if (DEBUG)
    std::cout << GREEN << "Bureaucrat Arguments Base Constructor called"
              << RESET << std::endl;

        if (grade < 1 || grade > 150)
        {
            try {
                if (grade < 1)
                    throw GradeTooHighException();
                if (grade > 150)
                    throw GradeTooLowException();
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
        else
            this->grade_ = grade;
    }


    // ----------------------------------------------------------------------------
    // ----------------------------------------------------------- Copy Constructor
    // ----------------------------------------------------------------------------
    Bureaucrat::Bureaucrat(const Bureaucrat& rhs) {
      
      if (DEBUG)
        std::cout << GREEN << "Bureaucrat Copy Constructor called"
                  << RESET << std::endl;

      (*this) = rhs;
    }


    // ----------------------------------------------------------------------------
    // ----------------------------------------------------------------- Destructor
    // ----------------------------------------------------------------------------
    Bureaucrat::~Bureaucrat() {
      if (DEBUG)
        std::cout << GREEN << "Bureaucrat base destructor called" << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- Overload
// ----------------------------------------------------------------------------
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (DEBUG)
    std::cout << ORANGE << "AForm assignment operator overload called" << RESET << std::endl;

	if (this != &rhs) {
		this->grade_ = rhs.grade_;
	}

	return (*this);
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- Methods
// ----------------------------------------------------------------------------
void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " 
		<< e.what() << std::endl;
	}
}

void Bureaucrat::execForm(AForm& form) {
	try {
		form.execute(*this);
		std::cout << LGREEN << this->getName() << RESET << " executed " 
                  << LGREEN << form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << LGREEN << this->getName() << RESET << " couldn't execute "
                  << LGREEN <<form.getName() << RESET << " because " 
		<< e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade() {
	if (grade_ - 1 < 1)
		throw Bureaucrat::GradeTooHighException();

	grade_ -= 1;
}

void Bureaucrat::decrementGrade() {
	if (grade_ + 1 > 150)
		throw Bureaucrat::GradeTooLowException();

	grade_ += 1;
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- Getters
// ----------------------------------------------------------------------------
const std::string Bureaucrat::getName() const { return (this->name_); }
int	Bureaucrat::getGrade() const { return (this->grade_); }


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- ostream
// ----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs) {

	lhs << LGREEN << rhs.getName() << RESET << " bureaucrat grade " << LGREEN << rhs.getGrade() << RESET << std::endl;

	return lhs;
}