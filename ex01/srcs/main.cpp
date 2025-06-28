#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "tuto : ./RPN [\"rpn expression\"]" << std::endl, 1);
	RPN rpn;
	std::string		expression = av[1];
	if (rpn.fillStack(expression))
		return (2);
	return (0);
}
