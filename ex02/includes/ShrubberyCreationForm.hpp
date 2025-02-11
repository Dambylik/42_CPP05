#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public :
	ShrubberyCreationForm(const std::string&);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	
	void execute(const Bureaucrat& executor) const;

protected:
	ShrubberyCreationForm();

private :
	const std::string& _target;
};

#endif // !SHRUBBERYCREATIONFORM_HPP