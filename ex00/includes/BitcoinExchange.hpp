#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// Colors /////////
#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define ROSE "\033[1;35m"
#define CYAN "\033[1;36m"

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

class Btc {
	private :
		std::map<std::string, float> _data;
	public :
		Btc();
		~Btc();
		Btc(const Btc &b);
		Btc	&operator=(const Btc &b);

		int		fillMap();
		void	printMap() const;
		int		recupInput(char *av) const;
		int		parseValue(float value) const;
		int		parseDate(std::string date) const;
		bool	isLeapYear(int year) const;
		bool	checkFormat(std::string date) const;
		float	getExchangeRate(const std::string &date) const;
};

#endif