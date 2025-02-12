#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main() {
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat b1 = Bureaucrat("Donald", 1);
        Intern i = Intern();

        std::cout << std::endl << b1;
        

        AForm* form = i.makeForm("Shrubbery Creation", "Merry_Christmas");
		if (!form)
		{
			std::cerr << "Error! Creating form failed" << std::endl;
			return (1);
		}

std::cout << *form;

        b1.signForm(*form);
        b1.executeForm(*form);
        b1.executeForm(*form);
        b1.executeForm(*form);

        std::cout << std::endl << "-----------------------------------" << std::endl;

        AForm* robot = i.makeForm("Robotomy", "Emmanuel");
        if (!robot)
		{
			std::cout << "Error! Creating form failed" << std::endl;
			delete form;
			return (1);
		}
        
        std::cout << *robot;
        b1.signForm(*robot);
        b1.executeForm(*robot);

        std::cout << std::endl << "-----------------------------------" << std::endl;

        AForm* mercy = i.makeForm("Presidential Pardon", "Olaf");
		if (!mercy)
		{
			std::cout << "Error creating form, abort" << std::endl;
			delete form;
			delete robot;
			return (1);
		}
      
        std::cout << mercy;
        b1.signForm(*mercy);
        b1.executeForm(*mercy);
        delete form;
		delete robot;
		delete mercy;

        std::cout << std::endl << "-----------------------------------" << std::endl;

    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }
}

