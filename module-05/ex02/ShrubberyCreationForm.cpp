#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form("ShrubberyCreationForm", 145, 137), _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::beExecuted() const
{
	std::ofstream	treeFile;
	std::string		fileName = this->_target + "_shrubbery";

	treeFile.open(fileName.c_str());
	treeFile <<	"            ,@@@@@@@,\n" <<
				"    ,,,.   ,@@@@@@/@@,  .oo8888o.\n" <<
				" ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" <<
				",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" <<
				"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" <<
				"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" <<
				"`&%\\ ` /%&'    |.|        \\ '|8'\n" <<
				"    |o|        | |         | |\n" <<
				"    |.|        | |         | |\n" <<
				"_\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	treeFile.close();
}