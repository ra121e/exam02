#include "vect2.hpp"
#include <stdexcept>


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

vect2	vect2::operator=(vect2 const &other)
{
	if(this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return (*this);
}

vect2::~vect2()
{}

vect2	vect2::operator+(vect2 const &other) const
{
	vect2	temp;
	temp._x = this->_x + other._x;
	temp._y = this->_y + other._y;
	return (temp);
}

vect2	vect2::operator-(vect2 const &other) const
{
	vect2	temp;
	temp._x = this->_x - other._x;
	temp._y = this->_y - other._y;
	return (temp);
}

vect2	vect2::operator-() const
{
	vect2	temp;
	temp._x = -_x;
	temp._y = -_y;
	return (temp);
}

vect2	vect2::operator*(int k) const
{
	vect2	temp;
	temp._x = this->_x * k;
	temp._y = this->_y * k;
	return (temp);
}

vect2	operator*(int k, vect2 const &other)
{
	vect2	temp;
	temp._x = other._x * k;
	temp._y = other._y * k;
	return (temp);
}

vect2	&vect2::operator++()
{
	this->_x++;
	this->_y++;
	return (*this);
}
vect2	vect2::operator++(int)
{
	vect2	temp = *this;
	this->_x++;
	this->_y++;
	return (temp);
}
vect2	&vect2::operator--()
{
	this->_x--;
	this->_y--;
	return (*this);
}
vect2	vect2::operator--(int)
{
	vect2	temp = *this;
	this->_x--;
	this->_y--;
	return (temp);
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
vect2	&vect2::operator*=(int k)
{
	this->_x = this->_x * k;
	this->_y = this->_y * k;
	return (*this);
}

int	&vect2::operator[](int i)
{
	if (i == 0)
	{
		return (this->_x);
	}
	else if (i == 1)
	{
		return (this->_y);
	}
	else
		throw std::out_of_range("out of range");
}
int	vect2::operator[](int i) const
{
	if (i == 0)
	{
		return (this->_x);
	}
	else if (i == 1)
	{
		return (this->_y);
	}
	else
		return (this->_y);
}

bool	vect2::operator==(vect2 const &other) const
{
	if (this->_x == other._x || this->_y == other._y)
		return (true);
	else
		return (false);
}
bool	vect2::operator!=(vect2 const &other) const
{
	if (this->_x == other._x || this->_y == other._y)
		return (false);
	else
		return (true);
}

std::ostream	&operator<<(std::ostream &os, vect2 const &other)
{
	os << "{" << other._x << ", " << other._y << "}";
	return (os);
}