#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


#include "Intern.hpp"

int main() {

    std::cout << std::endl << "--------------Robotomy Form---------------------" << std::endl;

    Intern Donald;

    AForm* form1 = Donald.makeForm("robotomy request", "Bender");
    if (form1) {
        std::cout << *form1;
        delete form1;
    }

    std::cout << std::endl << "----------------Shrubbery Form------------------" << std::endl;

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

    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf;
            delete rrf;
        }
    }
    return 0;
}

