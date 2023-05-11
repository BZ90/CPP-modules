#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &src) {(void)src;}

Serializer::~Serializer() {}

Serializer	&Serializer::operator=(const Serializer &rhs)
{
	(void)rhs; return (*this);
}

uintptr_t	Serializer::serialize(Data_t *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data_t	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data_t *>(raw));
}