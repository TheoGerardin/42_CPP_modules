#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::list<int> _lst;

    void validateInput(int argc, char** argv);
    
    template <typename Container>
    void fordJohnsonSort(Container& container);
    
    template <typename Container>
    void insertionSort(Container& container, size_t start, size_t end);
    
    template <typename Container>
    void mergeSort(Container& container, size_t start, size_t mid, size_t end);

public:
    PmergeMe();
    void processInput(int argc, char** argv);
    void sort();
    void displayResults();
};

#endif
