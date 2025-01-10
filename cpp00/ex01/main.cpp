#include "phonebook.hpp"

int main() {
	PhoneBook phonebook;
	std::string input;

	while(true) {
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command. Use ADD, SEARCH or EXIT" << std::endl;
	}
	return 0;
}