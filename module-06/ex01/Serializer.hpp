#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class	Serializer
{
	public:
		static uintptr_t	serialize(Data_t *ptr);
		static Data_t		*deserialize(uintptr_t );
	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer	&operator=(const Serializer &rhs);
};

#endif