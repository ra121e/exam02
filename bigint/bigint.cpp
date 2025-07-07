#include <string>
#include <algorithm>
#include <stdlib.h>
#include "bigint.hpp"

bigint::bigint():
	_value("0")
{}

bigint::bigint(unsigned long long n):
	_value(std::to_string(n))
{}

bigint::bigint(std::string const &s):
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

std::string	bigint::add(std::string num1, std::string num2)
{
	std::string	result;
	unsigned int carry = 0;
	std::string::reverse_iterator ita = num1.rbegin();
	std::string::reverse_iterator itb = num2.rbegin();
	while (ita != num1.rend() || itb != num2.rend() || carry)
	{
		unsigned long a = 0;
		unsigned long b = 0;
		if (ita != num1.rend())
			a = *ita++ - '0';
		if (itb != num2.rend())
			b = *itb++ - '0';
		unsigned long sum = a + b + carry;
		carry = sum / 10;
		result.push_back(sum % 10 + '0');
	}
	std::reverse(result.begin(), result.end());
	return (result);
}

bigint	bigint::operator+(bigint const &other) const
{
	bigint	result(add(this->_value, other._value));
	return (result);
}

bigint	bigint::operator+(unsigned long long n) const
{
	bigint	other(n);
	bigint	result(add(this->_value, other._value));
	return (result);
}

bigint	&bigint::operator+=(bigint const &other)
{
	this->_value = add(this->_value, other._value);
	return (*this);
}

bigint	&bigint::operator+=(unsigned long long n)
{
	bigint	other(n);
	this->_value = add(this->_value, other._value);
	return (*this);
}

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
std::string	bigint::leftShift(std::string s)
{
	s.push_back('0');
	return (s);
}

std::string	bigint::rightShift(std::string s)
{
	s.erase(s.end() - 1);
	return (s);
}

bigint	bigint::operator<<(unsigned long long n)
{
	unsigned long long i = 0;
	while (i++ < n)
		this->_value = leftShift(this->_value);
	return (*this);
}

bigint	bigint::operator>>(unsigned long long n)
{
	if (this->_value.size() <= n)
		return (this->_value = '0');
	unsigned long long i = 0;
	while (i++ < n)
		this->_value = rightShift(this->_value);
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, bigint const &other)
{
	os << other.getter();
	return (os);
}
