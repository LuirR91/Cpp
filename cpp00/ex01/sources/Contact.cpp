#include "Contact.hpp"

// Method to display contact info in table format
void Contact::display_row()
{
	std::string str[] = {first_name, last_name, nick_name, ""}; // Create array with 3 fields + empty terminator
	for (int i = 0; !str[i].empty(); i++)
	{
		if (str[i].length() > 10)
			std::cout << str[i].substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << str[i].substr(0, 10) << "|";
	}
	std::cout << std::endl;
}

// Method to display all contact information
void Contact::display_info()
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nick_name << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

// Method to validate phone number format
void Contact::number_validity()
{
	if (!std::cin)
		return;
	if (!isdigit(phone_number[0]) && phone_number[0] != '+')
		phone_number = "";
	for (int i = 1; phone_number[i]; i++)
	{
		if (!isdigit(phone_number[i]))
			phone_number = "";
	}
	if (phone_number.empty())
		std::cout << "Invalid phone number, try again." << std::endl;
}

// Method to check if contact has any data
int	Contact::is_empty()
{
	if (first_name.empty())
		return (1);
	return (0);
}

// Method to validate and format input
std::string Contact::field_formater(std::string prompt, int flag)
{
	int	i = -1;

	while (prompt[++i])
	{
		if ((isspace(prompt[i]) || prompt[i] == 27 || prompt[i] == 127) && flag != 4)
			return ("");
		if (flag == 1 && !std::isalpha(prompt[i]))
			return ("");
		if (flag == 2 && !std::isalnum(prompt[i]))
			return ("");
		if (flag == 3 && (prompt[i] < 32))
			return ("");
	}
	return (prompt);
}

// Method to get validated user input
std::string Contact::get_prompt(std::string message, int flag)
{
	std::string prompt;

	while (std::cin)
	{
		std::cout << message;
		std::getline(std::cin, prompt);
		if (!std::cin)
			break;
		prompt = field_formater(prompt, flag);
		if (!prompt.empty())
			break;
		else
			std::cerr << "Invalid prompt, try again." << std::endl;
	}
	return (prompt);
}

// Method to fill all contact fields
void Contact::fill_fields()
{
	first_name = get_prompt("First Name: ", 1);
	last_name = get_prompt("Last Name: ", 1);
	nick_name = get_prompt("Nickname: ", 3);
	phone_number = "";
	while (std::cin && phone_number.empty())
	{
		phone_number = get_prompt("Phone Number: ", 0);
		number_validity();
	}
	darkest_secret = get_prompt("Darkest Secret: ", 4);
}
