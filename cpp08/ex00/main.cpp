#include "EasyFind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "Testing with vector:" << std::endl;
    try {
        auto it = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        auto it = easyfind(vec, 6);
        std::cout << "Found value 6 at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "\nTesting with list:" << std::endl;
    try {
        auto it = easyfind(lst, 20);
        std::cout << "Found value 20" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    std::cout << "\nTesting with deque:" << std::endl;
    try {
        auto it = easyfind(deq, 400);
        std::cout << "Found value 400" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
