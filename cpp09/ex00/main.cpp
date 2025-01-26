#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
        std::cout << "Usage: ./btc \"filename\" " << std::endl;
	}
	else {
		BitcoinExchange btc;
		btc.compare(argv[1]);
	}
	return 0;
}
