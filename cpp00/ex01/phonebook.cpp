#include "phonebook.hpp"

void PhoneBook::addContact() {
	std::string input;
	do {
		std::cout << "First name : ";
		getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "\tCan't be empty." << std::endl;
		}
	} while (input.empty());
	contact[index].setFirstName(input);

	do {
		std::cout << "Last name : ";
		getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "\tCan't be empty." << std::endl;
		}
	} while (input.empty());
	contact[index].setLastName(input);

	do {
		std::cout << "Nickname : ";
		getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "\tCan't be empty." << std::endl;
		}
	} while (input.empty());
	contact[index].setNickName(input);

	do {
		std::cout << "Phone number : ";
		getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "\tCan't be empty." << std::endl;
		}
	} while (input.empty());
	contact[index].setPhoneNumber(input);

	do {
		std::cout << "Darkest secret : ";
		getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "\tCan't be empty." << std::endl;
		}
	} while (input.empty());
	contact[index].setDarkestSecret(input);

	std::cout << "Contact " << contact[index].getFirstName() << " " << contact[index].getLastName() << " added." << std::endl;
	index = (index + 1) % 8;
};

std::string PhoneBook::truncateString(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::searchContact() {
	int input;
	for (int i = 0; i < 8; ++i) {
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << truncateString(contact[i].getFirstName()) << "|"
				<< std::setw(10) << truncateString(contact[i].getLastName()) << "|"
				<< std::setw(10) << truncateString(contact[i].getNickName()) << std::endl;
	}
	while (true) {
		std::cout << "Enter contact index to display: ";
		if (!(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number between 0 and 7." << std::endl;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input < 0 || input >= 8) {
			std::cout << "Invalid index. Please enter a number between 0 and 7." << std::endl;
			continue;
		}
		break;
	}
	std::cout << "First Name: " << contact[input].getFirstName() << std::endl;
	std::cout << "Last Name: " << contact[input].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[input].getNickName() << std::endl;
	std::cout << "Phone Number: " << contact[input].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact[input].getDarkestSecret() << std::endl;
}