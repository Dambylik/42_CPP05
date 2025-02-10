/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:35:03 by okapshai          #+#    #+#             */
/*   Updated: 2025/02/10 18:34:33 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include <fstream>

#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::action() const {
    std::ofstream file((getTarget() + "_shrubbery").c_str(), std::ios::out); // Convert string to C-string

    if (!file) {
        std::cerr << "Error: Could not create file " << getTarget() + "_shrubbery" << std::endl;
        return;
    }

    // Write an ASCII tree into the file
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "       ||       " << std::endl;
    file << "       ||       " << std::endl;
    file << "       ||       " << std::endl;

    file.close();
}
