#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

#define SYMBOLS "+-*/"

class RPN {
    private :

    public :
        RPN();
        ~RPN();
        RPN(const RPN &r);
        RPN &operator=(const RPN &r);

        bool	isSymbol(std::string &s);
        void    printStack(std::stack<double> &stack);
        bool    calcul(std::string symbol, std::stack<double> &stack);
        bool	fillStack(std::string &expression);
};


#endif