#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int &argc, char **argv) : _argc(argc), _argv(argv) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _argc(src._argc), _argv(src._argv) {}

//	Checks if a char *string contains any characters that are not digits
void	PmergeMe::is_digits(const char *str)
{
	if (str[0] == '\0')
		throw (Error());
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > '9' || str[i] < '0')
			throw (Error());
	}
}

//	Checks if the program input is valid (mostly)
void	PmergeMe::is_valid_input(void)
{
	if (this->_argc < 2)
		throw (Error());
	for (int i = 1; i < this->_argc; i++)
		PmergeMe::is_digits(this->_argv[i]);
}

//	Fills a vector with the argv contents, converted to integers. Throws an Error() if the integer is out of range
void	PmergeMe::fill_vector(std::vector<int> &to_fill)
{
	long	buf;

	for (int i = 1; i < this->_argc; i++)
	{
		buf = strtol(this->_argv[i], NULL, 10);
		if (buf < 0 || buf > INT_MAX)
			throw (Error());
		else if (buf == 0 && this->_argv[i][0] != '0')
			throw (Error());
		to_fill.push_back((int)buf);
	}
}

//	Fills a deque with the argv contents, converted to integers. Throws an Error() if the integer is out of range
void	PmergeMe::fill_deque(std::deque<int> &to_fill)
{
	long	buf;

	for (int i = 1; i < this->_argc; i++)
	{
		buf = strtol(this->_argv[i], NULL, 10);
		if (buf < 0 || buf > INT_MAX)
			throw (Error());
		else if (buf == 0 && this->_argv[i][0] != '0')
			throw (Error());
		to_fill.push_back((int)buf);
	}
}

//	Inserts an element into a sorted deque in the correct position to keep it sorted
void	PmergeMe::deq_insert_element(std::deque<std::deque<int> > &deq, int elem)
{
	for (std::deque<std::deque<int> >::iterator it = deq.begin(); it != deq.end(); it++)
	{
		if (it->back() >= elem)
		{
			std::deque<int>	buf;
			buf.push_back(elem);
			deq.insert(it, buf);
			return ;
		}
	}
	std::deque<int>	buf;
	buf.push_back(elem);
	deq.insert(deq.end(), buf);
}

//	Inserts an element into a sorted vector in the correct position to keep it sorted
void	PmergeMe::vec_insert_element(std::vector<std::vector<int> > &vec, int elem)
{
	for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->back() >= elem)
		{
			std::vector<int>	buf;
			buf.push_back(elem);
			vec.insert(it, buf);
			return ;
		}
	}
	std::vector<int>	buf;
	buf.push_back(elem);
	vec.insert(vec.end(), buf);
}

//	Sorts a deque using the merge-insertion sort
std::deque<std::deque<int> >	PmergeMe::sort_deque(void)
{
//	Fill deque with integers
	std::deque<int>	values;
	PmergeMe::fill_deque(values);

//	Split values into pairs
	std::deque<std::deque<int> >	pairs;
	for (std::deque<int>::size_type i = 0; i < values.size(); i++)
	{
		std::deque<int>	buf;

		buf.push_back(values[i]);
		++i;
		if (i == values.size())
			pairs.push_back(buf);
		else
		{
			buf.push_back(values[i]);
			pairs.push_back(buf);
		}
		buf.erase(buf.begin(), buf.end());
	}

//	Sort contents of individual pairs
	for (std::deque<std::deque<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->size() > 1)
		{
			if (it->front() > it->back())
			{
				int	buf = it->back();
				it->back() = it->front();
				it->front() = buf;
			}
		}
	}
	std::deque<std::deque<int> >	result;

//	Sort pairs in ascending order
	for (std::deque<std::deque<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		for (std::deque<std::deque<int> >::size_type i = 0; i <= result.size(); i++)
		{
			if (i == result.size())
			{
				result.push_back(*it);
				break ;
			}
			else if (it->back() < result[i].back())
			{
				result.insert(result.begin() + i, *it);
				break ;
			}
		}
	}

//	Sort individual values
	int	j = 0;
	for (std::deque<std::deque<int> >::iterator it = result.begin(); it != result.end(); it++)
	{
		if (it->size() > 1)
		{
			int	buf = it->front();
			it->pop_front();
			PmergeMe::deq_insert_element(result, buf);
			it = result.begin() + j;
		}
		++j;
	}

//	Sort final value if there's a half pair
	if (values.size() % 2)
	{
		std::deque<std::deque<int> >::iterator it = result.end() - 1;
		int	buf = it->front();
		result.pop_back();
		deq_insert_element(result, buf);
	}

//	Return the sorted deque
	return (result);
}

//	Sorts a vector using the merge-insertion sort
std::vector<std::vector<int> >	PmergeMe::sort_vector(void)
{
//	Fill vector with integers
	std::vector<int>	values;
	PmergeMe::fill_vector(values);

//	Split values into pairs
	std::vector<std::vector<int> >	pairs;
	for (std::vector<int>::size_type i = 0; i < values.size(); i++)
	{
		std::vector<int>	buf;

		buf.push_back(values[i]);
		++i;
		if (i == values.size())
			pairs.push_back(buf);
		else
		{
			buf.push_back(values[i]);
			pairs.push_back(buf);
		}
		buf.erase(buf.begin(), buf.end());
	}

//	Sort contents of individual pairs
	for (std::vector<std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->size() > 1)
		{
			if (it->front() > it->back())
			{
				int	buf = it->back();
				it->back() = it->front();
				it->front() = buf;
			}
		}
	}
	std::vector<std::vector<int> >	result;

//	Sort pairs in ascending order
	for (std::vector<std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		for (std::vector<std::vector<int> >::size_type i = 0; i <= result.size(); i++)
		{
			if (i == result.size())
			{
				result.push_back(*it);
				break ;
			}
			else if (it->back() < result[i].back())
			{
				result.insert(result.begin() + i, *it);
				break ;
			}
		}
	}

//	Sort individual values
	int	j = 0;
	for (std::vector<std::vector<int> >::iterator it = result.begin(); it != result.end(); it++)
	{
		if (it->size() > 1)
		{
			int	buf = it->front();
			it->erase(it->begin());
			vec_insert_element(result, buf);
			it = result.begin() + j;
		}
		++j;
	}

//	Sort final value if there's a half pair
	if (values.size() % 2)
	{
		std::vector<std::vector<int> >::iterator it = result.end() - 1;
		int	buf = it->front();
		result.pop_back();
		vec_insert_element(result, buf);
	}

//	Returning the sorted vector
	return (result);
}

//	Returns the amount of time, in seconds, between two timespec structs
double	PmergeMe::get_seconds(struct timespec &start_time, struct timespec &end_time)
{
	return (double(end_time.tv_sec - start_time.tv_sec) + double(end_time.tv_nsec - start_time.tv_nsec) / 1e9);
}

//	Prints output, times the sorting, and calls the other functions
void	PmergeMe::merge_insert_sort(void)
{
	PmergeMe::is_valid_input();

	struct timespec	vec_start, vec_end, deq_start, deq_end;

//	Makes the sorting run slightly faster for some reason, also increases timing consistency
	std::vector<int>	useless;
	PmergeMe::fill_vector(useless);
	std::deque<int>		useless2;
	PmergeMe::fill_deque(useless2);

//	Print the first line of output
	std::cout << "Before:";
	for (int i = 1; i < this->_argc; i++)
		std::cout << " " << this->_argv[i];
	std::cout << std::endl;

//	Run and time the deque sorting algorithm
	clock_gettime(CLOCK_MONOTONIC, &deq_start);
	std::deque<std::deque<int> >	sorted_deq = PmergeMe::sort_deque();
	clock_gettime(CLOCK_MONOTONIC, &deq_end);
//	Run and time the vector sorting algorithm
	clock_gettime(CLOCK_MONOTONIC, &vec_start);
	std::vector<std::vector<int> >	sorted_vec = PmergeMe::sort_vector();
	clock_gettime(CLOCK_MONOTONIC, &vec_end);

//	Check if the vector and deque got sorted
	if (std::is_sorted(sorted_deq.begin(), sorted_deq.end()) == false || std::is_sorted(sorted_vec.begin(), sorted_vec.end()) == false)
		throw (Error());

//	Print the second line of output
	std::cout << "After: ";
	for (std::vector<std::vector<int> >::iterator it = sorted_vec.begin(); it != sorted_vec.end(); it++)
		std::cout <<  " " << it->front();
	std::cout << std::endl;

//	Print the third and fourth lines of output
	std::cout << std::fixed << "Time to process a range of " << sorted_deq.size() << " elements with std::deque  : " << PmergeMe::get_seconds(deq_start, deq_end) << " seconds" << std::endl;
	std::cout << std::fixed << "Time to process a range of " << sorted_vec.size() << " elements with std::vector : " << PmergeMe::get_seconds(vec_start, vec_end) << " seconds" << std::endl;
}
