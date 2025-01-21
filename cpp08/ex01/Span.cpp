#include "Span.hpp"

void addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is full, cannot add more numbers.");
	_numbers.push_back(number);
}


int shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int longestSpan() const;
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");

	int minElem = *std::min_element(_numbers.begin(), _numbers.end());
	int maxElem = *std::max_element(_numbers.begin(), _numbers.end());

	return maxElem - minElem;
}
