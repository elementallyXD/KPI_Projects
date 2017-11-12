#include "Library.h"

namespace BL {

	int rand(int x, int y)
	{
		srand(time(NULL));
		int r;
		r = std::rand() % (y - x + 1) + x;
		return r;
	}

	double rand(int x, int y, int x1, int y1, int size)
	{
		srand(time(NULL));
		int i, dot;
		double d;
		static int percent;

		i = std::rand() % (y - x + 1) + x;
		dot = std::rand() % (y1 - x1 + 1) + x1;

		switch (size)
		{
		case 1: 10;;
		case 2: 100;;
		case 3: 1000;;
		case 4: 10000;;
		default: 10;;
		}

		d = ((double)dot / size) + i;

		return d;
	}

	void rrand() {
		/*
		1 - 80 
		2 - 10
		3 - 5
		4 - 5
		*/
		int size, r;

		r = rand (1, 99);
		
		if (r <= 80) std::cout << "1" << std::endl;
		else if ((r <= 90) && (r > 80)) std::cout << "2" << std::endl;
		else if ((r <= 95) && (r > 90)) std::cout << "3" << std::endl;
		else std::cout << "4" << std::endl;
		
		std::cout << "r = " << r << std::endl;
	}
}