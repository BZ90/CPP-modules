#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int	main(void)
{
	Data_t		pre;
	Data_t		*post;
	uintptr_t	mid;

	pre.a = 1;
	pre.b = 2;
	std::cout << "Address of Data struct before serialization: " << &pre << std::endl;
	mid = Serializer::serialize(&pre);
	std::cout << "Value of Data struct address after serialization: " << mid << std::endl;
	post = Serializer::deserialize(mid);
	std::cout << "Address of Data struct after deserialization: " << post << std::endl;


	if (&pre == post && pre.a == post->a && pre.b == post->b)
	{
		std::cout << "Pass: Post serialization is the same as pre serialization" << std::endl;
	}
	else
		std::cout << "Fail: Post serialization is different from pre serialization" << std::endl;
}