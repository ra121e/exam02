#include <string>
#include <iostream>
#include "bigint.hpp"

int	main(void)
{
	bigint const a(42);
	bigint	b(21), c, d(1337), e(d);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "b + a = " << b + a << std::endl;

	return (0);
}