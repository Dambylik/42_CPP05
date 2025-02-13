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

    AForm* form2 = Donald.makeForm("shrubbery creation", "Home");
    if (form2) {
        std::cout << *form2;
        delete form2;
    }

    std::cout << std::endl << "------------Presidential Pardon Form--------------" << std::endl;

    AForm* form3 = Donald.makeForm("presidential pardon", "Emmanuel");
    if (form3) {
        std::cout << *form3;
        delete form3;
    }

std::cout << std::endl << "------------Invalid Form--------------" << std::endl;

    AForm* form4 = Donald.makeForm("Boubou", "Lambda");
    if (form4) {
        delete form4;
    }

std::cout << std::endl << "------------Subject exmmple--------------" << std::endl;

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

