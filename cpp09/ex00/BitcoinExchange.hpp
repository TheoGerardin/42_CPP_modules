#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    std::string findClosestDate(const std::string& date);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
};

#endif
