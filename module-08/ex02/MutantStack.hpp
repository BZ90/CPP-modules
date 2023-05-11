#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class	MutantStack : public std::stack<T>
{
	public:
	MutantStack();
	MutantStack(const MutantStack &src);
	~MutantStack();
	MutantStack	&operator=(const MutantStack &rhs);

	typedef typename std::deque<T>::iterator			iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse_iterator;

	iterator				begin();
	iterator				end();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
};

#include "MutantStack.tpp"

#endif