#include "../includes/PMergeMe.hpp"

PMergeMe::PMergeMe() : _entry("default"), _sorted("default") {}

PMergeMe::~PMergeMe(){}

PMergeMe::PMergeMe(const std::string &entry, int nbEntry) {
	_entry = entry;
	_nbEntry = nbEntry;
}

PMergeMe::PMergeMe(const PMergeMe &p) {
	(void)p;
}

PMergeMe	&PMergeMe::operator=(const PMergeMe &p) {
	(void)p;
}

const std::string	&PMergeMe::getEntry() const {return (_entry);}
const std::string	&PMergeMe::getSorted() const {return (_sorted);}
const int			&PMergeMe::getNbEntry() const {return (_nbEntry);}
const double		&PMergeMe::getDTime() const {return (_dTime);}
const double		&PMergeMe::getVTime() const {return (_vTime);}
const std::deque<int>	&PMergeMe::getDNumbers() const {return (_dNumbers);}
const std::vector<int>	&PMergeMe::getVNumbers() const {return (_vNumbers);}

void	PMergeMe::checkEntry(const std::string &entry) {
	std::string validChar = "0123456789 ";

	for (size_t i = 0; i < entry.size(); i++)
	{
		if (validChar.find(entry[i] == std::string::npos))
			throw InvalidChar();
	}
}

void	PMergeMe::fillContainer(const std::string &entry) {
	int	cnt = 0;
	int	tmp = 0;
	std::vector<std::pair<int, int>> vTmp;
	clock_t timeUsedS;
	clock_t timeUsedE;
	// (void)_nbEntry;

	checkEntry(entry);
	for (size_t i = 0; i < entry.size(); i++)
	{
		if (i != 0 && isdigit(entry[i - 1]) && entry[i] == ' ')
		{
			std::istringstream iss(entry.substr(cnt, i - cnt));
			if (iss >> tmp)
			{
				_dNumbers.push_back(tmp);
				_vNumbers.push_back(tmp);
			}
			else
				throw NegativeInt();
			if (i + 1 < entry.size())
				cnt = i + 1;
			if (i + 1 < entry.size())
				i++;
		}
		timeUsedS = clock();
		vMergeList(_vNumbers);
		timeUsedE = clock();
		_vTime = static_cast<double>(timeUsedE - timeUsedS) / CLOCKS_PER_SEC * 1000000;
		timeUsedS = clock();
		dMergeList(_dNumbers);
		timeUsedE = clock();
		_dTime = static_cast<double>(timeUsedE - timeUsedS) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << _nbEntry << " elements with std::vector : " << _vTime << " us." << std::endl;
		std::cout << "Time to process a range of " << _nbEntry << " elements with std::deque : " << _dTime << " us." << std::endl;

	}
}

void	PMergeMe::vMergeList(std::vector<int> &v) {
	std::vector<std::pair<int, int>> afterFJ;
	std::vector<int> res;

	vCreatePairs(vec);
	afterFJ = vFordJohnsonSort(_vPairs);
	for (std::vector<std::pair<int, int>>::iterator it = afterFJ.begin(); it != afterFJ.end(); ++it)
	{
		res.push_back(it->first);
	}
	for (std::vector<std::pair<int, int>>::iterator it = afterFJ.begin())
}

void	PMergeMe::dMergeList(std::deque<int> &d) {

}