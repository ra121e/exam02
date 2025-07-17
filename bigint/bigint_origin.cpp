#include <string>
#include <algorithm>
#include <stdlib.h>
#include "bigint_origin.hpp"

bigint::bigint():
	_value("0")
{}

bigint::bigint(unsigned long long n):
	_value(std::to_string(n))
{}

// std::string	bigint::removeLeadingZero(std::string const &s)
// {
// 	if (s.empty() || s.find_first_not_of('0') == std::string::npos)
// 		return ("0");
// 	else
// 	{
// 		size_t	a = s.find_first_not_of('0');
// 		return (s.substr(a));
// 	}
// }

// bigint::bigint(std::string const &s):
// 	_value(s)
// {}

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

bigint	bigint::operator+(bigint const &other) const
{
	bigint	result;
	unsigned int sum = 0;
	auto ita = _value.rbegin();
	auto itb = other._value.rbegin();
	while (ita != _value.rend() || itb != other._value.rend() || sum)
	{
		if (ita != _value.rend())
			sum += *ita++ - '0';
		if (itb != other._value.rend())
			sum += *itb++ - '0';
		result._value.push_back(sum % 10 + '0');
		sum /= 10;
	}
	std::reverse(result._value.begin(), result._value.end());
	result._value.pop_back();

	return (result);
}

// bigint	bigint::operator+(unsigned long long n) const
// {
// 	bigint	other(n);
// 	bigint	result(add(this->_value, other._value));
// 	return (result);
// }

bigint	&bigint::operator+=(bigint const &other)
{
	*this = *this + other;
	return (*this);
}

// bigint	&bigint::operator+=(unsigned long long n)
// {
// 	bigint	other(n);
// 	this->_value = add(this->_value, other._value);
// 	return (*this);
// }

bigint	&bigint::operator++(void)
{
	*this += 1;
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	tmp = *this;
	*this += 1;
	return (tmp);
}

bool	bigint::operator==(bigint const &other) const
{
	if (this->_value == other._value)
		return (true);
	return (false);
}

bool	bigint::operator!=(bigint const &other) const
{
	if (this->_value != other._value)
		return (true);
	return (false);
}

bool	bigint::operator<(bigint const &other) const
{
	if (this->_value.size() != other._value.size())
		return (this->_value.size() < other._value.size());
	return (this->_value < other._value);
}

bool	bigint::operator>=(bigint const &other) const
{
	return (!(*this < other));
}

bool	bigint::operator>(bigint const &other) const
{
	return (other < *this);
}

bool	bigint::operator<=(bigint const &other) const
{
	return (!(other < *this));
}

// shift operation
std::string	bigint::leftShift(std::string s) const
{
	s.push_back('0');
	return (s);
}

std::string	bigint::rightShift(std::string s) const
{
	s.erase(s.end() - 1);
	return (s);
}

bigint	bigint::operator<<(unsigned long long n) const
{
	unsigned long long	i = 0;
	bigint				tmp(*this);
	while (i++ < n)
		tmp._value = leftShift(tmp._value);
	return (tmp);
}

bigint	bigint::operator>>(unsigned long long n) const
{
	bigint	tmp(*this);
	if (tmp._value.size() <= n)
	{
		tmp._value = "0";
		return tmp;
	}
	unsigned long long i = 0;
	while (i++ < n)
		tmp._value = rightShift(tmp._value);
	return (tmp);
}

bigint	&bigint::operator<<=(unsigned long long n)
{
	unsigned long long i = 0;
	while (i++ < n)
		this->_value = leftShift(this->_value);
	return (*this);
}

bigint	&bigint::operator>>=(unsigned long long n)
{
	if (this->_value.size() <= n)
		this->_value = '0';
	else
	{
		unsigned long long i = 0;
		while (i++ < n)
			this->_value = rightShift(this->_value);
	}
	return (*this);
}
std::ostream	&operator<<(std::ostream &os, bigint const &other)
{
	os << other.getter();
	return (os);
}
