#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class PresidentialPardonForm : public AForm {
public :
	PresidentialPardonForm(const std::string&);
	~PresidentialPardonForm();
	
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);

	void	execute(const Bureaucrat&) const;

private :
	const std::string& target_;
};

#endif // !PRESIDENTIALPARDONFORM_HPP
