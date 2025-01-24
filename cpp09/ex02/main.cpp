#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [positive integers...]" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    
    try {
        clock_t start_vec, end_vec, start_list, end_list;
        
        sorter.processInput(argc, argv);
        
        start_vec = clock();
        sorter.sort();
        end_vec = clock();
        
        sorter.displayResults();
        
        double vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << argc - 1 
                  << " elements with std::vector : " 
                  << std::fixed << std::setprecision(5) << vec_time << " us" << std::endl;
        
        start_list = clock();
        sorter.sort();
        end_list = clock();
        
        double list_time = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << argc - 1 
                  << " elements with std::list : " 
                  << std::fixed << std::setprecision(5) << list_time << " us" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
