#include "../includes/BitcoinExchange.hpp"

Btc::Btc(){}

Btc::~Btc(){}

Btc::Btc(const Btc &b){
	_data = b._data;
}

Btc	&Btc::operator=(const Btc &b) {
	_data = b._data;
	return (*this);
}

//////////////////////////////////////////////////////////

// ifstream lit un fichier
// istringstream lit une chaine de caractere

int	Btc::fillMap() {
	std::ifstream	infile("data.csv");
	if (infile.is_open() == false)
		return (std::cerr << "Error: could not open data.csv" << std::endl, 1);
	
	std::string	line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		int	sepPos = line.find(',', 0);
		std::string	date = line.substr(0, sepPos);
		std::string valueStr = line.substr(sepPos + 1);

		float	value;
		std::istringstream	iss(valueStr);
		if (!(iss >> value))
			return (std::cerr << "Error: bad value." << valueStr << std::endl, 2);
		_data[date] = value;
	}
	infile.close();
	return (0);
}

void	Btc::printMap() const {
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++)
		std::cout << it->first << ", " << std::fixed << std::setprecision(2) << it->second << std::endl;
}

int	Btc::recupInput(char *av) const {
	std::ifstream input(av);
	if (!input.is_open())
		return (std::cerr << "Error: could not open " << av << std::endl, 1);
	std::string line;
	std::getline(input, line);
	std::string	date;
	while (std::getline(input, line))
	{
		std::istringstream	iss(line);
		char				sep;
		float				value = 0.0;
		float				rate = 0.0;
		std::string 		rest;
		if (iss >> date >> sep >> value >> rest)
			std::cerr << "Error: bad line : " << line << std::endl;
		else if (parseValue(value) != 0)
			;
		else if (parseDate(date))
			std::cerr << "Error: bad input : " << date << std::endl;
		else
		{
			rate = getExchangeRate(date);
			std::cout << date << ": " << value << " = " << rate * value << std::endl;
		}
	}
	input.close();
	return (0);
}

int	Btc::parseValue(float value) const{
	if (value < 0)
		return (std::cerr << "Error: not a positive number." << std::endl, 1);
	else if (value > 1000)
		return (std::cerr << "Error: number too large." << std::endl, 2);
	return (0);
}

int	Btc::parseDate(std::string date) const{
	if (checkFormat(date))
		return (1);
	std::istringstream iss(date);
	int	year, month, day;
	int	maxDays = 31;
	char delim;
	iss >> year >> delim >> month >> delim >> day;
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
		return (2);
	else if (year == 2009 && month ==1 && day < 02)
		return (3);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDays = 30;
	else if (month == 2)
	{
		if (isLeapYear(year))
			maxDays = 29;
		else
			maxDays = 28;
	}

	if (day > maxDays)
		return (1);
	return (0);
}

bool	Btc::checkFormat(std::string date) const{
	std::istringstream	iss(date);
	std::string year, month, day;

	std::getline(iss, year, '-');
	std::getline(iss, month, '-');
	std::getline(iss, day, '-');

	if (year.empty() || month.empty() || day.empty())
		return (true);
	return (false);
}

bool Btc::isLeapYear(int year) const{
	return (year % 4 == 0 && year %100 != 0) || (year % 400 == 0);
}

float Btc::getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date); //return value >= date or date.end()
	if (it == _data.end())
		return ((--it)->second);
	if (it->first > date)
		it--;
	return (it->second);
}
