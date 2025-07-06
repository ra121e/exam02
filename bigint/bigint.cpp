#include <string>
#include <stdlib.h>
#include "bigint.hpp"

bigint::bigint():
	_value("0")
{}

bigint::bigint(unsigned long long n):
	_value(std::to_string(n))
{}

bigint::bigint(std::string &s):
	_value(s)
{}

bigint::bigint(bigint const &other):
	_value(other._value)
{}

bigint	&bigint::operator=(bigint const &other)
{
	if (this != &other)
	{
		_value = other._value;
	}
	return (*this);
}

bigint::~bigint()
{}

std::string const	&bigint::getter(void) const
{
	return (this->_value);
}

bigint	bigint::operator+(bigint const &other)
{
	bigint	result;

	unsigned int carry = 0;
	std::string::reverse_iterator ita = this->_value.rbegin();
	std::string::reverse_iterator itb = other._value.rbegin();
	while (ita != this->_value.rend() || itb != other._value.rend() || carry)
	{
		unsigned long a = 0;
		unsigned long b = 0;
		if (ita != this->_value.rend())
			a = strtoul(static_cast<const char>(*ita), NULL, 10);
		if (itb != other._value.rend())
			b = strtoul(static_cast<const char>(*itb), NULL, 10);
		unsigned long sum = a + b;
		result._value.insert(0, std::to_string(sum));
		++ita;
		++itb;
	}

	return (result);
}

std::ostream	&operator<<(std::ostream &os, bigint const &other)
{
	os << other.getter();
	return (os);
}
