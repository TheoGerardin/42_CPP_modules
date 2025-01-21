#include "EasyFind.hpp"

int main()
{
    try {
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;

        int arrList[] = {10, 20, 30, 40, 50};
        std::list<int> lst(arrList, arrList + sizeof(arrList) / sizeof(arrList[0]));
        std::cout << "Found: " << *easyfind(lst, 20) << std::endl;

        std::cout << "Trying to find a missing value..." << std::endl;
        easyfind(vec, 42);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}