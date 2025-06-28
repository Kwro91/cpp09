#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

#define SYMBOLS "+-*/"

bool	isSymbol(std::string &s);
bool	fillStack(std::string &expression, std::stack<int> stack);

#endif