#include "Phonebook.hpp"
#include <csignal>

int	main()
{
	Phonebook	book;
	std::string	prompt;
	std::signal(SIGINT, SIG_IGN);

	std::cout << "<<<   Welcome to my phonebook   >>>" << std::endl;
	std::cout << std::endl << "Type ADD to save a new contact" << std::endl;
	std::cout << "SEARCH to search for a contact" << std::endl;
	std::cout << "EXIT to exit the program" << std::endl;

	while (std::getline(std::cin, prompt) && (prompt != "EXIT" || !std::cin))
	{
		if (prompt == "ADD")
			book.add_contact();
		else if (prompt == "SEARCH")
			book.display_contacts();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
