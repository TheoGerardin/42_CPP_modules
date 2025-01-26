#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>

class BitcoinExchange{
private:
	std::map<std::string, float>_data;
	float get_value_closest(std::string date);

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);

    ~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &other);

    void compare(std::string filename);
};

#endif
