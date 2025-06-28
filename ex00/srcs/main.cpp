#include <iostream>
#include "../includes/BitcoinExchange.hpp"

int main (int ac, char **av) {
	if (ac != 2)
	{
		std::cerr << "Wrong usage for btc. Please retry with ./btc fileName" << std::endl;
		return 0;
	}
	Btc btc;
	if (btc.fillMap())
		return (2);
	if (btc.recupInput(av[1]))
		return (3);
	return (0);
}