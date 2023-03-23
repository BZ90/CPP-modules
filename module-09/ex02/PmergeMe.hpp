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

//	Utility functions
bool	is_digits(char *str);
bool	is_valid_input(int argc, char **argv);
double	get_seconds(struct timespec &start_time, struct timespec &end_time);
void	vec_insert_element(std::vector<std::vector<int> > &vec, int elem);
void	deq_insert_element(std::deque<std::deque<int> > &deq, int elem);

//	Conversion from char **, to deque<int>/vector<int>
void	fill_deque(int argc, char **argv, std::deque<int> &to_fill);
void	fill_vector(int argc, char **argv, std::vector<int> &to_fill);

//	Sorting function prototypes
std::vector<std::vector<int> >	sort_vector(int argc, char **argv);
std::deque<std::deque<int> >	sort_deque(int argc, char **argv);
void	merge_insert_sort(int argc, char **argv);

//	Generic exception class
class	Error : public std::exception
{
	virtual const char *what() const throw() {return ("Error");};
};

#endif