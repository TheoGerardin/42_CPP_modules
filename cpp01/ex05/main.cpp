#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Testing Harl at DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTesting Harl at INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTesting Harl at WARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTesting Harl at ERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTesting Harl with unknown level:" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
