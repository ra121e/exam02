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
	std::cout << "a + 42 = " << a + 42 << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;
	std::cout << "(b += e) = " << (b += e) << std::endl;
	std::cout << "b = " << b << std::endl; // b = 21
	std::cout << "++b = " << ++b << std::endl; // ++b = 22
	std::cout << "b++ = " << b++ << std::endl; // b++ = 22 (après cette ligne b = 23)
	std::cout << "b = " << b << std::endl; // b = 21
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d == d) = " << (d != d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d != a) = " << (d == a) << std::endl; // (d != a) = 1
	return (0);
}