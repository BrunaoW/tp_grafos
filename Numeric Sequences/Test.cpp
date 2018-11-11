#include "Container.h"
#include <iostream>

std::ostream& operator<< (std::ostream& stream, Seq& obj) {
	obj.print(stream);
	return stream;
}

void printAny(Seq & obj, int min, int max)
{
	if (min >= 1 && max <= obj.length())
	{
		for (int i = min; i <= max; i++)
		{
			auto x = obj.elem(i);
			std::cout << std::to_string(x) << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	Container c; 
	c.addFibonnacci(15);
	c.addLucas(15);
	c.addPell(15);
	c.addPentagonal(15);
	c.addQuadrados(15);
	c.addTriangular(15);
	c.printSequences(1, 12);

	system("pause");

	return 0;
}