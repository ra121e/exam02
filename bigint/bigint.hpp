#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <iostream>


class bigint
{
	public:
		bigint();
		bigint(unsigned long long n);
		bigint(std::string const &s);
		bigint(bigint const &other);
		bigint	&operator=(bigint const &other);
		~bigint();

		std::string const	&getter(void) const;

		bigint	operator+(bigint const &other) const;
		bigint	operator+(unsigned long long n) const;
		bigint	&operator+=(bigint const &other);
		bigint	&operator+=(unsigned long long n);
		bigint	&operator++(void);
		bigint	operator++(int);
		bool	operator==(bigint const &other) const;
		bool	operator!=(bigint const &other) const;
		bool	operator<(bigint const &other) const;
		bool	operator>=(bigint const &other) const;
		bool	operator>(bigint const &other) const;
		bool	operator<=(bigint const &other) const;
	private:
		std::string _value;
		static std::string	add(std::string num1, std::string num2);
};

std::ostream	&operator<<(std::ostream &os, bigint const &other);

#endif