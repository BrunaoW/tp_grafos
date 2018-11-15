#include "Container.h"
#include <iostream>
#include <algorithm>
#include <string>

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

	bool running = true; 
	std::string response; 
	int value = 0;

	while (running)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "  List of Codes\n" << std::endl;

		std::cout << " Add Sequence:\n" << std::endl;
		std::cout << "  'fib' : Fibonnacci" << std::endl;
		std::cout << "  'luc' : Lucas " << std::endl;
		std::cout << "  'pel' : Pell " << std::endl;
		std::cout << "  'pen' : Pentagonal " << std::endl;
		std::cout << "  'qua' : Quadrados " << std::endl;
		std::cout << "  'tri' : Triangular " << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << " Print elements:\n" << std::endl;
		std::cout << "  'full' : Print full sequences." << std::endl;
		std::cout << "  'elem' : Print only i-th element of every sequence." << std::endl;
		std::cout << "  'rang' : Print from i-th element to j-th element of every sequence." << std::endl;

		std::cout << "\n Type code and press [ENTER] ('q' or 'quit' to exit): ";
		std::cin >> response; 
		std::transform(response.begin(), response.end(), response.begin(), ::toupper);

		if (response == "FIB")
		{
			std::cout << std::endl;
			std::cout << " Starting number of elements: ";
			std::cin >> response;

			try
			{
				value = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue; 
			}

			c.addFibonnacci(value);

			std::cout << "\n Added Fibonnacci with " << value << " elements!\n"<< std::endl;
			system("pause");
		}

		else if (response == "LUC")
		{
			std::cout << std::endl;
			std::cout << " Starting number of elements: ";
			std::cin >> response;

			try
			{
				value = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			c.addLucas(value);

			std::cout << "\n Added Lucas with " << value << " elements!\n" << std::endl;
			system("pause");
		}

		else if (response == "PEL")
		{
			std::cout << std::endl;
			std::cout << " Starting number of elements: ";
			std::cin >> response;

			try
			{
				value = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			c.addPell(value);

			std::cout << "\n Added Pell with " << value << " elements!\n" << std::endl;
			system("pause");
		}

		else if (response == "PEN")
		{
			std::cout << std::endl;
			std::cout << " Starting number of elements: ";
			std::cin >> response;

			try
			{
				value = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			c.addPentagonal(value);

			std::cout << "\n Added Pentagonal with " << value << " elements!\n" << std::endl;
			system("pause");
		}

		else if (response == "QUA")
		{
			std::cout << std::endl;
			std::cout << " Starting number of elements: ";
			std::cin >> response;

			try
			{
				value = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			c.addQuadrados(value);

			std::cout << "\n Added Quadrados with " << value << " elements!\n" << std::endl;
			system("pause");
		}

		else if (response == "TRI")
		{
			std::cout << std::endl;
			std::cout << " Starting number of elements: ";
			std::cin >> response;

			try
			{
				value = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			c.addTriangular(value);

			std::cout << "\n Added Triangular with " << value << " elements!\n" << std::endl;
			system("pause");
		}

		else if (response == "FULL")
		{
			std::cout << std::endl;
			c.printSequences();
			std::cout << std::endl;
			system("pause");
		}

		else if (response == "ELEM")
		{
			std::cout << std::endl;
			std::cout << " Element number (index starts at 1): ";
			std::cin >> response;

			int i=0;

			try
			{
				i = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			std::cout << std::endl;
			c.printSequences(i);
			std::cout << std::endl;
			system("pause");
		}

		else if (response == "RANG")
		{
			int i = 0, j = 0;

			std::cout << std::endl;
			std::cout << " Start element (index starts at 1): ";
			std::cin >> response;

			try
			{
				i = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			std::cout << std::endl;
			std::cout << " End element (index starts at 1): ";
			std::cin >> response;
			
			try
			{
				j = std::stoi(response);
			}

			catch (...)
			{
				std::cout << "\n Invalid argument. Try again.\n" << std::endl;
				system("pause");
				continue;
			}

			std::cout << std::endl;
			c.printSequences(i,j);
			std::cout << std::endl;

			system("pause");
		}

		else if (response == "QUIT" || response == "Q")
		{
			exit(0);
		}

		else
		{
			std::cout << "\n Invalid argument. Try again.\n" << std::endl;
			system("pause");
		}

		

	}

	system("pause");

	return 0;
}