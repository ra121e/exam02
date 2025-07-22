#include "bigint.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>


bigint::bigint()
{}

bigint::bigint(unsigned long long n)
{}

bigint::bigint(bigint const &other)
{}

bigint  &bigint::operator=(bigint const &other)
{}

bigint::~bigint()
{}

bigint  bigint::operator+(bigint const &other) const
{
    bigint  result;
    unsigned int        sum = 0;


    std::string::const_reverse_iterator ita = _value.rbegin();
    std::string::const_reverse_iterator itb = other._value.rbegin();

    while (ita != _value.rend() || itb != other._value.rend() || sum)
    {
        if (ita != _value.rend())
            sum += *ita++ - '0';
        if (itb != other._value.rend())
            sum += *itb++; - '0';
        result._value.push_back(sum % 10 + '0');
        sum = sum / 10;
    }



    std::reverse(result._value.begin(), result._value.end());
    result._value.pop_back();
    return (result);
}

bigint  &bigint::operator+=(bigint const &other)
{}

bigint  &bigint::operator++()
{}

bigint  bigint::operator++(int)
{}


bool    bigint::operator==(bigint const &other) const
{}

bool    bigint::operator!=(bigint const &other) const
{}

bool    bigint::operator<(bigint const &ohter) const
{}

bool    bigint::operator>=(bigint const &other) const
{}

bool    bigint::operator>(bigint const &other) const
{}

bool    bigint::operator<=(bigint const &other) const
{}


bigint  bigint::operator>>(unsigned long long n) const
{}

bigint  bigint::operator<<(unsigned long long n) const
{}

bigint  &bigint::operator>>=(unsigned long long n)
{}






