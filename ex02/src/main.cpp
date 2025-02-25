#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
    
    srand(time(NULL));
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat b1("Donald", 1);
        ShrubberyCreationForm form("Merry_Christmas");
        
        std::cout << std::endl;

        std::cout << b1;
        std::cout << form;

        b1.signForm(form);
        b1.executeForm(form);

        std::cout << std::endl << "-----------------------------------" << std::endl;

        RobotomyRequestForm robot("ex");
        
        std::cout << robot;
        b1.signForm(robot);
        b1.executeForm(robot);
        for (int i = 0; i < 10; ++i)
            b1.executeForm(robot);

        std::cout << std::endl << "-----------------------------------" << std::endl;

        PresidentialPardonForm mercy("Olaf");
        
        std::cout << mercy;
        b1.signForm(mercy);
        b1.executeForm(mercy);

        std::cout << std::endl << "-----------------------------------" << std::endl;

    }
    catch ( const std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }

}
