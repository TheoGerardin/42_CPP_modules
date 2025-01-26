#include "PmergeMe.hpp"

int main(int ac, char **av)
{
   if (ac < 2)
   {
		std::cout << "Usage: ./PmergeMe <number1> <number2> ..." << std::endl;
		return (1);
   }
   PmergeMe merge;

   if (merge.parse_args(av + 1))
	  return (1);

   if (merge.merge_vector() || merge.merge_list())
	  return (1);

   merge.display();

   return (0);
}
