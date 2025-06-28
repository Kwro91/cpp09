#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &r) {(void)r;}

RPN	&RPN::operator=(const RPN &r) {
	(void)r;
	return (*this);
}


bool	RPN::isSymbol(std::string &s){
	if (s.size() != 1)
		return (false);
	
	std::string symbols = SYMBOLS;
	for (size_t i = 0; i < symbols.size(); i++)
		if (s[0] == symbols[i])
			return (true);
	return (false);
}

void	RPN::printStack(std::stack<double> &stack){
	// std::stack<double> tmp = stack;
	while (!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

bool	RPN::calcul(std::string symbol, std::stack<double> &stack){
	if (stack.size() <= 1)
		return (std::cerr << "Error: not enough number." << std::endl, false);
	double	n2 = stack.top();
	stack.pop();
	double	n1 = stack.top();
	stack.pop();

	if (symbol == "+")
		stack.push(n1 + n2);
	else if (symbol == "-")
		stack.push(n1 - n2);
	else if (symbol == "*")
		stack.push(n1 * n2);
	else if (symbol == "/")
	{
		if (n2 == 0)
			return (std::cerr << "Error: divide by zero." << std::endl, false);
		stack.push(n1 / n2);
	}
	return (true);
}

bool	RPN::fillStack(std::string &expression){
	std::istringstream	iss(expression);
	std::string	str;
	std::stack<double> stack;

	while(iss >> str)
	{
		if ((str.size() != 1) || (!std::isdigit(str[0]) && !isSymbol(str)))
			return (std::cerr << "Error: Wrong input -> " << str[0] << "." << std::endl, true);
		else if (std::isdigit(str[0]))
			stack.push(std::atof(str.c_str()));
		else if (isSymbol(str))
			if (!calcul(str, stack))
				return (1);
	}
	printStack(stack);
	return (0);
}