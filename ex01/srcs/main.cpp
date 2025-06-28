#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "tuto : ./RPN [\"rpn expression\"]" << std::endl, 1);

	std::stack<int>	stack;
	std::string		expression = av[1];
	if (fillStack(expression, stack))
		return (2);
	return (0);
}