#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testMutantStack() {
    std::cout << "=== Testing MutantStack ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\nIterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    std::cout << "Size of copied stack: " << s.size() << std::endl;
}

void testList() {
    std::cout << "\n=== Testing List (for comparison) ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back: " << lst.back() << std::endl;
    
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "\nIterating through List:" << std::endl;
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main() {
    testMutantStack();
    testList();

    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    MutantStack<std::string> words;
    words.push("Hello");
    words.push("World");
    
    MutantStack<std::string> wordsCopy(words);
    MutantStack<std::string> wordsAssign = words;
    
    std::cout << "Original top: " << words.top() << std::endl;
    std::cout << "Copy top: " << wordsCopy.top() << std::endl;
    std::cout << "Assigned top: " << wordsAssign.top() << std::endl;
    
    MutantStack<int> numbers;
    for (int i = 1; i <= 5; ++i)
        numbers.push(i);
        
    std::cout << "\nReverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = numbers.rbegin(); 
         rit != numbers.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}
