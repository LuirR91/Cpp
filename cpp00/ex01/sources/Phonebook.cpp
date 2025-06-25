#include "Phonebook.hpp"

void Phonebook::add_contact()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Fill the fields to add a contact." << std::endl << std::endl;
	for (int i = 6; i >= 0; i--)
		contact[i + 1] = contact[i];
	contact[0].fill_fields();
	if (std::cin)
	{
		std::cout << std::endl << "Contact Added." << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

void Phonebook::display_contacts()
{
	int			i;
	std::string prompt;

	if (contact[0].is_empty())
	{
		std::cout << "There is no information on the Phonebook" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (i = 0; i <= 7 && !contact[i].is_empty(); i++)
	{
		std::cout << "|" << "         " << i + 1 << "|";
		contact[i].display_row();
	}
	std::cout << std::endl << "Index of the entry to display: ";
	while (std::cin)
	{
		std::getline(std::cin, prompt);
		if (!std::cin)
			break ;
		if (prompt.length() == 1)
			i = prompt[0] - 48;
		else
			i = 0;
		if (i >= 1 && i <= 8 && !contact[i - 1].is_empty())
		{
			std::cout << std::endl;
			contact[i - 1].display_info();
			break ;
		}
		else
			std::cout << "Invalid index, select again: ";
	}
	if (std::cin)
		std::cout << "---------------------------------------------" << std::endl;
}
