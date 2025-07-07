#include "vect2.hpp"

int	main(void)
{
	vect2 v1;			// 0,0
	vect2 v2(1,2);		// 1,2
	const vect2 v3(v2);	// 1,2
	vect2 v4 = v2;		// 1,2
	std::cout << "v1 " << v1 << std::endl;
	std::cout << "v2 " << v2 << std::endl;
	std::cout << "v3 " << v3 << std::endl;
	std::cout << "v4 " << v4 << std::endl;

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl; // should be the same as above

	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;
	return (0);
}