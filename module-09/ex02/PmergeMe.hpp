#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <algorithm>
# include <string>
# include <iostream>
# include <ios>
# include <ctime>
# include <cstdlib>
# include <climits>
# include <sys/time.h>
# include <time.h>


class PmergeMe
{
	private:
		const int	_argc;
		char ** const _argv;

		void	is_digits(const char *str);
		void	is_valid_input(void);
		double	get_seconds(struct timespec &start_time, struct timespec &end_time);
		void	vec_insert_element(std::vector<std::vector<int> > &vec, int elem);
		void	deq_insert_element(std::deque<std::deque<int> > &deq, int elem);
		void	fill_deque(std::deque<int> &to_fill);
		void	fill_vector(std::vector<int> &to_fill);
		std::vector<std::vector<int> >	sort_vector(void);
		std::deque<std::deque<int> >	sort_deque(void);
		PmergeMe();
		PmergeMe	&operator=(const PmergeMe &rhs);
	public:
		PmergeMe(int &argc, char **argv);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		void	merge_insert_sort();
};

//	Generic exception class
class	Error : public std::exception
{
	virtual const char *what() const throw() {return ("Error");};
};

#endif