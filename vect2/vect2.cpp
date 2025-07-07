#include <iostream>
#include "vect2.hpp"

vect2::vect2():
	_x(0),
	_y(0)
{}

vect2::vect2(int x, int y):
	_x(x),
	_y(y)
{}

vect2::vect2(vect2 const &other):
	_x(other._x),
	_y(other._y)
{}

vect2	&vect2::operator=(vect2 const &other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return (*this);
}

vect2	vect2::operator+(vect2 const &other) const
{
	vect2	tmp;
	tmp._x = this->_x + other._x;
	tmp._y = this->_x + other._y;
	return (tmp);
}

vect2	vect2::operator-(vect2 const &other) const
{
	vect2	tmp;
	tmp._x = this->_x - other._x;
	tmp._y = this->_x - other._y;
	return (tmp);
}

vect2	vect2::operator-() const
{
	vect2	tmp;
	tmp._x = -_x;
	tmp._y = -_y;
	return (*this);
}

vect2	vect2::operator*(int k) const
{
	vect2	tmp;
	tmp._x = this->_x * k;
	tmp._y = this->_y * k;
	return (tmp);
}

vect2	operator*(int k, vect2 const &other)
{
	vect2	tmp;
	tmp._x = other._x * k;
	tmp._y = other._y * k;
	return (tmp);
}

int		&vect2::operator[](size_t i)
{
	if (i == 0)
		return (this->_x);
	else if (i == 1)
		return (this->_y);
	else
		throw std::out_of_range("index is out of range");
}

int		vect2::operator[](size_t i) const
{
	if (i == 0)
		return (this->_x);
	else if (i == 1)
		return (this->_y);
	else
		throw std::out_of_range("index is out of range");
}

vect2	&vect2::operator++()
{
	this->_x++;
	this->_y++;
	return (*this);
}

vect2	vect2::operator++(int)
{
	vect2	tmp = *this;
	this->_x++;
	this->_y++;
	return (tmp);
}

vect2	&vect2::operator--()
{
	this->_x--;
	this->_y--;
	return (*this);
}

vect2	vect2::operator--(int)
{
	vect2	tmp = *this;
	this->_x--;
	this->_y--;
	return (tmp);
}

vect2	&vect2::operator+=(vect2 const &other)
{
	this->_x = this->_x + other._x;
	this->_y = this->_y + other._y;
	return (*this);
}

vect2	&vect2::operator-=(vect2 const &other)
{
	this->_x = this->_x - other._x;
	this->_y = this->_y - other._y;
	return (*this);
}

vect2	&vect2::operator*=(vect2 const &other)
{
	this->_x = this->_x * other._x;
	this->_y = this->_y * other._y;
	return (*this);
}

vect2	&vect2::operator*=(int k)
{
	this->_x = this->_x * k;
	this->_y = this->_y * k;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, vect2 const &other)
{
	os << "{" << other._x << ", " << other._y << "}";
	return (os);
}