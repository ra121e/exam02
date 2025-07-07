#include <iostream>

class vect2
{
	public:
		vect2();
		vect2(int x, int y);
		vect2(vect2 const &other);
		vect2	&operator=(vect2 const &other);

	private:
		int	_x;
		int	_y;
};