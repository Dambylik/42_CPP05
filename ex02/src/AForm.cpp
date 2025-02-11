#include "AForm.hpp"

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------- Constructor
// ----------------------------------------------------------------------------
AForm::AForm()
	  :name_("Name undefined"), isSigned_(false), gradeToSign_(10), gradeToExec_(10) {
  if (DEBUG)
    std::cout << ORANGE << "AForm base constructor called" << RESET << "\n";
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Args Constructor
// ----------------------------------------------------------------------------
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
                       : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) {

std::cout << ORANGE << "AForm base with args constructor called" << RESET
              << "\n";

    if (gradeToExec < 1 || gradeToExec > 150 || gradeToSign < 1 || gradeToSign > 150 ) {
        
        try {
            if (gradeToExec_ < 1 || gradeToSign_ < 1)
                throw GradeTooHighException();
            if (gradeToExec_ > 150 || gradeToSign_ > 150)
                throw GradeTooLowException();
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Copy Constructor
// ----------------------------------------------------------------------------
AForm::AForm(const AForm& rhs)
	  : name_(rhs.getName()), isSigned_(false), gradeToSign_(rhs.getGradeToSign()), gradeToExec_(rhs.getGradeToExec()) {

  if (DEBUG)
    std::cout << ORANGE << "AForm Base Copy Constructor Called" << RESET
              << std::endl;

	*this = rhs;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- Destructor
// ----------------------------------------------------------------------------
AForm::~AForm() {
  if (DEBUG)
    std::cout << ORANGE << "AForm base destructor called" << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- Overload
// ----------------------------------------------------------------------------
AForm& AForm::operator=(const AForm& rhs) {

	if (DEBUG)
    std::cout << ORANGE << "AForm assignment operator overload called" << RESET << std::endl;

	if (this != &rhs) {
		this->isSigned_ = rhs.getIsSigned();
	}

	return *this;
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- Getters
// ----------------------------------------------------------------------------
const std::string& AForm::getName() const {	return this->name_; }
bool AForm::getIsSigned() const { return this->isSigned_; } 
int AForm::getGradeToSign() const { return (this->gradeToSign_); }
int	AForm::getGradeToExec() const { return (this->gradeToExec_); }

void AForm::beSigned(const Bureaucrat& bae) {
	if (bae.getGrade() <= this->gradeToSign_)
		this->isSigned_ = true;
	else
		throw(Bureaucrat::GradeTooLowException());
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- ostream
// ----------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &lhs, AForm const &rhs) {
  if (DEBUG)
    std::cout << ORANGE << "AForm Base << Assignment Operator Called" << RESET
              << std::endl;

  if ((rhs.getGradeToExec() < 1 || rhs.getGradeToExec() > 150) ||
      (rhs.getGradeToSign() < 1 || rhs.getGradeToSign() > 150)) {
    try {
      if (rhs.getGradeToSign() < 1 || rhs.getGradeToExec() < 1)
        throw "Exception error occured.\nGrade too high.\n";
      if (rhs.getGradeToSign() > 150 || rhs.getGradeToExec() > 150)
        throw "Exception error occured.\nGrade too low.\n";
    } catch (const char *e) {
      std::cerr << e << std::endl;
    }
  } else {
    lhs << "AForm " << LGREEN << rhs.getName() << RESET
        << ", created with a grade of " << LGREEN << rhs.getGradeToSign()
        << RESET << ".\n\n";
  }

  return lhs;
}