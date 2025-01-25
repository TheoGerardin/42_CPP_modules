#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;
    
    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || 
        dash1 != '-' || dash2 != '-') 
        return false;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) {
    char* end;
    double val = std::strtod(value.c_str(), &end);
    
    return *end == '\0' && val >= 0 && val <= 1000 && val != std::numeric_limits<double>::infinity();
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, float>::iterator it = _database.lower_bound(date);
    
    if (it == _database.begin() && it->first > date)
        return "";

    if (it == _database.end() || it->first > date)
        --it;

    return it->first;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line, date;
    float rate;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::getline(ss, date, ',');
        ss >> rate;
        _database[date] = rate;
    }
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line, date, rawValue;
    float value;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        if (!(std::getline(ss, date, '|') >> value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(0, date.find_first_not_of(" "));
        date.erase(date.find_last_not_of(" ") + 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(rawValue = ss.str().substr(ss.str().find('|') + 1))) {
            if (rawValue.empty() || rawValue.find_first_not_of(" ") == std::string::npos)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (std::strtod(rawValue.c_str(), NULL) > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string closestDate = findClosestDate(date);
        if (closestDate.empty()) {
            std::cerr << "Error: no data for this date." << std::endl;
            continue;
        }

        float rate = _database[closestDate];
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}
