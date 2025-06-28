#include "../includes/RPN.hpp"

bool	isSymbol(std::string &s){
	if (s.size() != 1)
		return (false);
	
	std::string symbols = SYMBOLS;
	for (size_t i = 0; i < symbols.size(); i++)
		if (s[0] == symbols[i])
			return (true);
	return (false);
}

void	printStack(std::stack<int> stack){
	std::stack<int> tmp = stack;
	while (!tmp.empty())
	{
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << std::endl;
}

bool	calcul(std::string symbol, std::stack<int> &stack){
	if (stack.size() <= 1)
		return (std::cerr << "Error: not enough number." << std::endl, false);
	int	n2 = stack.top();
	stack.pop();
	int	n1 = stack.top();
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
	return (false);
}

bool	fillStack(std::string &expression, std::stack<int> stack){
	std::istringstream	iss(expression);
	std::string	str;

	while(iss >> str)
	{
		if ((str.size() != 1) || (!std::isdigit(str[0]) && !isSymbol(str)))
			return (std::cerr << "Error: Wrong input -> " << str[0] << "." << std::endl, true);
		else if (std::isdigit(str[0]))
			stack.push(str[0] - 48);
		else if (isSymbol(str))
			if (calcul(str, stack))
				return (1);
	}
	printStack(stack);
	return (0);
}