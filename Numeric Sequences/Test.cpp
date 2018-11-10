#include "Fibonnacci.h"
#include <iostream>

int main()
{
	Fibonnacci fi= Fibonnacci();
	fi.elem(100);
	fi.print(std::cout);
	system("pause");
	return 0;
}