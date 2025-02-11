#include "ShrubberyCreationForm.hpp"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Args Constructor
// ----------------------------------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
					  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    if (DEBUG)
        std::cout << CYAN << "Shrubbery Creation Form args constructor called"
				  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------- Destructor
// ----------------------------------------------------------------------------
ShrubberyCreationForm::~ShrubberyCreationForm() {
    if (DEBUG)
        std::cout << CYAN << "Shrubbery Creation Form destructor calledaa"
				  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------- Copy Constructor
// ----------------------------------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
					  : AForm(rhs), _target(rhs._target) {
    if (DEBUG)
        std::cout << CYAN << "Shrubbery Creation Form copy constructor called"
				  << RESET << std::endl;
}


// ----------------------------------------------------------------------------
// ------------------------------------------------------------------- Overload
// ----------------------------------------------------------------------------
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {


    std::cout << CYAN << "Shrubbery Creation Form assignment operator called"
				  << RESET << std::endl;

	(void)rhs;
	return (*this);
}


// ----------------------------------------------------------------------------
// -------------------------------------------------------------------- Methods
// ----------------------------------------------------------------------------
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getIsSigned() == false)
		throw(AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw(AForm::GradeTooLowException());

	std::string l = this->_target + "_shrubbery";
	const char* p = l.c_str();
	std::ofstream file(p, std::ios_base::app);
	file << "                                                         ." << std::endl;
	file << "                                              .         ;  " << std::endl;
	file << "                 .              .              ;%     ;;   " << std::endl;
	file << "                   ,           ,                :;%  %;   " << std::endl;
	file << "                    :         ;                   :;%;'     .,   " << std::endl;
	file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
	file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
	file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
	file << "                            ;@%. :@%%  %@@%;       " << std::endl;
	file << "                              %@bd%%%bd%%:;     " << std::endl;
	file << "                                #@%%%%%:;;" << std::endl;
	file << "                                %@@%%%::;" << std::endl;
	file << "                                %@@@%(o);  . '         " << std::endl;
	file << "                                %@@@o%;:(.,'         " << std::endl;
	file << "                            `.. %@@@o%::;         " << std::endl;
	file << "                               `)@@@o%::;         " << std::endl;
	file << "                                %@@(o)::;        " << std::endl;
	file << "                               .%@@@@%::;         " << std::endl;
	file << "                               ;%@@@@%::;.          " << std::endl;
	file << "                              ;%@@@@%%:;;;. " << std::endl;
	file << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
	file.close();
}
//     // Write an ASCII tree into the file
//     file << "      /\\      " << std::endl;
//     file << "     /\\*\\     " << std::endl;
//     file << "    /\\O\\*\\    " << std::endl;
//     file << "   /*/\\/\\/\\   " << std::endl;
//     file << "  /\\O\\/\\*\\/\\  " << std::endl;
//     file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
//     file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
//     file << "       ||       " << std::endl;
//     file << "       ||       " << std::endl;
//     file << "       ||       " << std::endl;

//     file.close();
// }
