#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &src){
	*this = src;
};

PmergeMe::~PmergeMe(){};

PmergeMe & PmergeMe::operator=(const PmergeMe &other){
	if (this != &other){
		this->args = other.args;
		this->vector_sorted = other.vector_sorted;
		this->vector_duration = other.vector_duration;
		this->list_sorted = other.list_sorted;
		this->list_duration = other.list_duration;
	}
	return *this;
};

int is_sorted(const std::vector<int> &v){
	for(size_t i = 0; i < v.size() - 1; i++){
		if (v[i] > v[i + 1])
			return 0;
	}
	return 1;
}

int digital_string(const char *str){
	while(*str){
		if (!std::isdigit(*str))
			return 0;
		str++;
	}
	return 1;
}

int PmergeMe::parse_args(char **av){
	int i = 0;
	while (av[i]){
		if (!digital_string(av[i])){
			std::cout << "Error: " << av[i] << " isn't a number" << std::endl;
			return 1;
		}
		long num = std::atol(av[i]);
		if (num < 0){
			std::cout << "Error: " << av[i] << " isn't a positive number" << std::endl;
			return 1;
		}
		else if (num > __INT_MAX__){
			std::cout << "Error: " << av[i] << " must be smaller than INT MAX " << std::endl;
			return 1;
		}
		this->args.push_back(static_cast<int>(num));
		i++;
	}
	return 0;
}

int PmergeMe::merge_vector(){
	std::clock_t start_timer = std::clock();

	if (is_sorted(this->args)){
		std::cout << "Already sorted" << std::endl;
		this->vector_sorted = this->args;
		return 1;
	}
	if (this->args.size() == 1){
		this->vector_sorted.push_back(this->args[0]);
		std::cout << "Only one number" << std::endl;
		return 1;
	}

	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i < this->args.size(); i += 2){
		int first = this->args[i];
		int second = (i + 1 < this->args.size() ? this->args[i + 1] : -1);
		if (second != -1 && first > second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}
	std::vector<int> mins;
	for (size_t i = 0; i < pairs.size(); ++i)
		mins.push_back(pairs[i].first);
	std::sort(mins.begin(), mins.end());


	std::vector<int> sorted = mins;
	for (size_t i = 0; i < pairs.size(); ++i){
		if (pairs[i].second != -1){
			std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
			sorted.insert(pos, pairs[i].second);
		}
	}
	this->vector_sorted = sorted;
	this->vector_duration = static_cast<double>(std::clock() - start_timer) / CLOCKS_PER_SEC * 1000;
	return 0;
}

int PmergeMe::merge_list(){
	std::clock_t start_time = std::clock();

	if (is_sorted(this->args)){
		std::cout << "Already is sorted" << std::endl;
		this->list_sorted = std::list<int>(this->args.begin(), this->args.end());
		return 1;
	}
	if (this->args.size() == 1){
		this->list_sorted.push_back(this->args[0]);
		std::cout << "Only one number" << std::endl;
		return 1;
	}
	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i < this->args.size(); i += 2){
		int first = this->args[i];
		int second = (i + 1 < this->args.size() ? this->args[i + 1] : -1);
		if (second != -1 && first > second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}
	std::vector<int> mins;
	for(size_t i = 0; i < pairs.size(); ++i)
		mins.push_back(pairs[i].first);
	std::sort(mins.begin(), mins.end());

	std::list<int> sorted;
	for (size_t i = 0; i < pairs.size(); ++i){
		std::list<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
		sorted.insert(pos, pairs[i].first);
	}

	this->list_sorted = sorted;
	this->list_duration = static_cast<double>(std::clock() - start_time) / CLOCKS_PER_SEC * 1000;
	return 0;
}


void PmergeMe::display(){
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = args.begin(); it != args.end(); ++it){
		std::cout << *it << " " ;
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = vector_sorted.begin(); it != vector_sorted.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << args.size() << " elements with std::vector : " << vector_duration << std::endl;
	std::cout << "Time to process a range of " << args.size() << " elements with std::list : " << list_duration << std::endl;
}
