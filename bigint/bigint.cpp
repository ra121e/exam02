#include <string>
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

std::ostream	&operator<<(std::ostream &os, bigint const &other)
{
	os << other.getter();
	return (os);
}
