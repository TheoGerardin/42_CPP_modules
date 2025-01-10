#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include "contact.hpp"

class PhoneBook {
	private :
		Contact contact[8];
		int		index;

	public :
		PhoneBook() : index(0) {}
		void addContact();
		std::string truncateString(const std::string& str);
		void searchContact();

};