#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

void PmergeMe::validateInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        char* end;
        long value = std::strtol(argv[i], &end, 10);
        
        if (*end != '\0' || value < 0) 
            throw std::runtime_error("Invalid input");
        
        _vec.push_back(value);
        _lst.push_back(value);
    }
}

template <typename Container>
void PmergeMe::insertionSort(Container& container, size_t start, size_t end) {
    for (size_t i = start + 1; i <= end; ++i) {
        auto key = std::next(container.begin(), i);
        auto j = std::prev(key);
        
        while (j != std::prev(container.begin(), start) && *j > *key) {
            std::iter_swap(j, key);
            key = j;
            j = std::prev(j);
        }
    }
}

template <typename Container>
void PmergeMe::mergeSort(Container& container, size_t start, size_t mid, size_t end) {
    Container left(std::next(container.begin(), start), 
                   std::next(container.begin(), mid + 1));
    Container right(std::next(container.begin(), mid + 1), 
                    std::next(container.begin(), end + 1));
    
    auto left_it = left.begin();
    auto right_it = right.begin();
    auto container_it = std::next(container.begin(), start);
    
    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            *container_it = *left_it;
            ++left_it;
        } else {
            *container_it = *right_it;
            ++right_it;
        }
        ++container_it;
    }
    
    while (left_it != left.end()) {
        *container_it = *left_it;
        ++left_it;
        ++container_it;
    }
    
    while (right_it != right.end()) {
        *container_it = *right_it;
        ++right_it;
        ++container_it;
    }
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    size_t n = container.size();
    
    if (n <= 1) return;
    
    for (size_t block_size = 1; block_size < n; block_size *= 2) {
        for (size_t start = 0; start < n; start += 2 * block_size) {
            size_t mid = std::min(start + block_size - 1, n - 1);
            size_t end = std::min(start + 2 * block_size - 1, n - 1);
            
            if (mid < end) {
                mergeSort(container, start, mid, end);
            }
        }
        
        insertionSort(container, 0, n - 1);
    }
}

void PmergeMe::processInput(int argc, char** argv) {
    _vec.clear();
    _lst.clear();
    validateInput(argc, argv);
}

void PmergeMe::sort() {
    fordJohnsonSort(_vec);
    fordJohnsonSort(_lst);
}

void PmergeMe::displayResults() {
    // Before sorting
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    // After sorting
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}
