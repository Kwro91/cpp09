#ifndef PMERGERME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <utility>
#include <deque>
#include <exception>

class PMergeMe{
	private:
		int	_nbEntry;
		std::string							_entry;
		std::string							_sorted;
		std::deque<int>						_dNumbers;
		std::vector<int>					_vNumbers;
		std::vector<std::pair<int, int>>	_vPairs;
		std::deque<std::pair<int, int>>		_dPairs;
		double								_dTime;
		double								_vTime;
		

	public:
		PMergeMe();
		~PMergeMe();
		PMergeMe(const PMergeMe &p);
		PMergeMe	&operator=(const PMergeMe &p);
		PMergeMe(const std::string &entry, int nbEntry);

		const std::string		&getEntry() const;
		const std::string		&getSorted() const;
		const int				&getNbEntry() const;
		const double			&getDTime() const;
		const double			&getVTime() const;
		const std::deque<int>	&getDNumbers() const;
		const std::vector<int>	&getVNumbers() const;

		void	checkEntry(const std::string &entry);
		void	fillContainer(const std::string &entry);

		void	vMergeList(std::vector<int> &v);
		void	dMergeList(std::deque<int> &d);


		//////////////////////////////_EXCEPTION_//////////////////////////////


		class InvalidChar : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Error: invalid character. Please use only '0123456789 '.");
				}
		};

		class NegativeInt : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("Error: forbidden negative number.");
				}
		};
};

#endif