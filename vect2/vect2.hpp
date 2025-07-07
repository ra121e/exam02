#include <iostream>
#include <cstddef>

class vect2
{
	public:
		vect2();
		vect2(int x, int y);
		vect2(vect2 const &other);
		vect2	&operator=(vect2 const &other);

		vect2	operator+(vect2 const &other) const;
		vect2	operator-(vect2 const &other) const;
		vect2	operator*(int k) const;

		int		&operator[](size_t i);
		int		operator[](size_t i) const;

		vect2	&operator++();
		vect2	operator++(int);
		vect2	&operator--();
		vect2	operator--(int);

		vect2	&operator+=(vect2 const &other);
		vect2	&operator-=(vect2 const &other);
		vect2	&operator*=(vect2 const &other);
		vect2	&operator*=(int	k);

		friend std::ostream	&operator<<(std::ostream &os, vect2 const &other);
	private:
		int	_x;
		int	_y;
};
