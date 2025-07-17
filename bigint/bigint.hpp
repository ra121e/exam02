#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
    public:
        bigint();
        bigint(unsigned long long n);
        bigint(bigint const &other);
        bigint  &operator=(bigint const &other);
        ~bigint();

        bigint  operator+(bigint const &other) const; //const
        bigint  &operator+=(bigint const &other);

        bigint  &operator++();
        bigint  operator++(int); //none const

        bool    operator==(bigint const &other) const;
        bool    operator!=(bigint const &other) const;
        bool    operator<(bigint const &other) const;
        bool    operator>=(bigint const &other) const;
        bool    operator>(bigint const &other) const;
        bool    operator<=(bigint const &other) const;

        bigint  operator>>(unsigned long long k) const; //const
        bigint  operator<<(unsigned long long k) const; //const
        bigint  &operator>>=(unsigned long long k);
        bigint  &operator<<=(unsigned long long k);
        bigint  &operator>>=(bigint const &other);

        friend std::ostream &operator<<(std::ostream &os, bigint const &other);
    private:
        std::string _value;
};

#endif