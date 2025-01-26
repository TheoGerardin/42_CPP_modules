#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::ifstream file;

	file.open("data.csv");
	if (file){
		std::string line;
		while (getline(file, line)){
			int start = 0;
			int end = line.find(",");
			this->_data[line.substr(start, end)] = atof(line.substr(end + 1, line.length()).c_str());
		}
	}
	else{
		std::cerr << "Error: Can't open the file" << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other){
	if (this != &other)
		this->_data = other._data;
	return *this;
}

float BitcoinExchange::get_value_closest(std::string date){
	std::map<std::string, float>::iterator it;
	std::string closest_date;
	float closest_value = -1.0f;

	for (it = _data.begin(); it != _data.end(); ++it){
		const std::string &current_date = it->first;
		float current_value = it->second;

		if (current_date <= date){
			if (current_date.empty() || current_date >= closest_date){
				closest_date = current_date;
				closest_value = current_value;
			}
		}
	}
	return closest_value;
}

void BitcoinExchange::compare(std::string filename){
	std::ifstream file(filename.c_str());

	if (file){
		std::string line;
		getline(file, line);
		if (line != "date | value"){
			std::cout << "Error: bad input => " << line << std::endl;
			return;
		}
		while(getline(file, line)){
			size_t sep = line.find("|");
			if (sep == std::string::npos){
				std::cout << "Error: bad input => " << line << std::endl;
			}
			else{
				std::string date = line.substr(0, sep);
				std::string value = line.substr(sep + 1);
				if (date.empty() || value.empty()){
					std::cout << "Error: bad input => " << line << std::endl;
				}
				else{
					float max = atof(value.c_str());
					if (max > 1000)
						std::cout << "Error: too large a number." << std::endl;
					else if(max < 0)
						std::cout << "Error: not a positive number." << std::endl;
					else if(get_value_closest(date) < 0)
						std::cout << "Error: not previous date." << std::endl;
					else{
						std::cout << date << " => " << value << " = " << (get_value_closest(date) * max) << std::endl;
					}
				}
			}
		}
		file.close();
	}
	else
		std::cerr << "Error: Can't open the file " << filename << std::endl;
}
