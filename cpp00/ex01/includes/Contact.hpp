#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		int			is_empty();
		void		fill_fields();
		void		display_row();
		void		display_info();
		void		number_validity();
		std::string	get_prompt(std::string message, int flag);
		std::string	field_formater(std::string prompt, int flag);
};

#endif
