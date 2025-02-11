#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>


int main(void)
{
    std::cout << "\n-------------------CEO----------------------------------" << std::endl;

    try {
        Bureaucrat bur = Bureaucrat("Big Boss", 1);
	    ShrubberyCreationForm form("42Paris");
	
	    std::cout << bur;
        std::cout << form;
        bur.signForm(form);
        bur.execForm(form);

        RobotomyRequestForm dead("Olly");
        std::cout << dead;
        bur.signForm(dead);
        bur.execForm(dead);
        
        PresidentialPardonForm mercy("Olly");
        std::cout << mercy;
        bur.signForm(mercy);
        bur.execForm(mercy);
    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n-------------------INTERN-------------------------" << std::endl;

    try {
        Bureaucrat bur = Bureaucrat("Intern", 150);
	    ShrubberyCreationForm form("Useless Form");
	
	    std::cout << bur;
        std::cout << form;
        
        bur.signForm(form);
        bur.execForm(form);

        RobotomyRequestForm dead("Olly");
        std::cout << dead;
        bur.signForm(dead);
        bur.execForm(dead);
        
        PresidentialPardonForm mercy("Olly");
        std::cout << mercy;
        bur.signForm(mercy);
        bur.execForm(mercy);
        
        std::cout << std::endl;

    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

    return (0);
}

