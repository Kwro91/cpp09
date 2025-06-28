#include "../includes/PMergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error: need more arguments" << std::endl, 1);
    
    PMergeMe sequence;
    sequence.sortFJ(av);

    return (0);
}