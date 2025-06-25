#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];
	
	public:
		void	add_contact();
		void	display_contacts();
};

#endif