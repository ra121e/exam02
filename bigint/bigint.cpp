#include "bigint.hpp"
#include <algorithm> // to_string()
#include <stdlib.h> 
#include <string>

bigint::bigint():_value("0")
{}

bigint::bigint(unsigned long long n): _value(std::to_string(n))
{} // to_string

bigint::bigint(bigint const &other): _value(other._value)
{}

bigint  &bigint::operator=(bigint const &other)
{
    if (this!= &other)
    {
        this->_value = other._value;
    }
    return (*this);
}

bigint::~bigint()
{}

bigint  bigint::operator+(bigint const &other) const //const
{
    bigint result;
    unsigned int    sum = 0;

    std::string::const_reverse_iterator ita = _value.rbegin();
    std::string::const_reverse_iterator itb = other._value.rbegin();

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

bigint  &bigint::operator+=(bigint const &other)
{
    *this = *this + other;
    return (*this);
}

bigint  &bigint::operator++()
{
    *this += 1;
    return (*this);
}

bigint  bigint::operator++(int) //none const
{
    bigint  temp;
    temp = *this;
    *this += 1;
    return (temp);
}

bool    bigint::operator==(bigint const &other) const
{
    return (this->_value == other._value);
}

bool    bigint::operator!=(bigint const &other) const
{
    return (this->_value != other._value);
}

bool    bigint::operator<(bigint const &other) const
{
    if (this->_value.size() != other._value.size())
        return (this->_value.size() < other._value.size());
    return (this->_value < other._value);
}

bool    bigint::operator>=(bigint const &other) const
{
    return (!(*this < other));
}

bool    bigint::operator>(bigint const &other) const
{
    return (other < *this);
}

bool    bigint::operator<=(bigint const &other) const
{
    return (!(other < *this));
}

bigint  bigint::operator<<(unsigned long long k) const //const
{
    bigint  temp(*this);
    if (temp._value == "0")
    {
        temp._value = "0";
        return (temp);
    }
    for (unsigned long long i = 0; i < k; ++i)
        temp._value.push_back('0');
    return (temp);
}

bigint  bigint::operator>>(unsigned long long k) const //const
{
    bigint  temp;
    temp = *this;
    if (temp._value.size() <= k)
    {
        temp._value = "0";
        return (temp);
    }
    else
    {
        for (unsigned long long i = 0; i < k; ++i)
            temp._value.erase(temp._value.end() - 1);
        return (temp);
    }
}

bigint  &bigint::operator<<=(unsigned long long k)
{
    if (this->_value == "0")
    {
        this->_value = "0";
        return (*this);
    }
    for (unsigned long long i = 0; i < k; ++i)
        this->_value.push_back('0');
    return (*this);
}

bigint  &bigint::operator>>=(unsigned long long k)
{
    if (this->_value.size() <= k)
    {
        this->_value = "0";
        return (*this);
    }
    else
    {
        for (unsigned long long i = 0; i < k; ++i)
            this->_value.erase(this->_value.end() - 1);
        return (*this);
    }
}

bigint  &bigint::operator>>=(bigint const &other)
{
    if (this->_value.size() <= std::strtoull(other._value.c_str(), nullptr, 10))
    {
        this->_value = "0";
        return (*this);
    }
    else
    {
        for (unsigned long long i = 0; i < std::strtoull(other._value.c_str(), nullptr, 10); ++i)
            this->_value.erase(this->_value.end() - 1);
        return (*this);
    }
}

std::ostream &operator<<(std::ostream &os, bigint const &other)
{
    os << other._value;
    return (os);
}