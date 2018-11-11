#include "Container.h"


void Container::printAny(Seq & obj, int min, int max)
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

void Container::printSequences()
{
	for(int i = 0; i < sequences.size(); i++)
		printAny( *(sequences[i]), 1, (sequences[i])->length() );
}

void Container::printSequences(unsigned index)
{
	for (int i = 0; i < sequences.size(); i++)
	{
		if (index >=1 && index <= (sequences[i])->length())
		{
			printAny(*(sequences[i]), index, index);
		}
		else
		{
			std::cout << "Index "<< std::to_string(index) << "out of range \n";
		}
	}
		
}

void Container::printSequences(unsigned min, unsigned max)
{
	for (int i = 0; i < sequences.size(); i++)
	{
		if (min >= 1 && i <= (sequences[min])->length() && max >= 1 && max <= (sequences[i])->length())
		{
			printAny(*(sequences[i]), min, max);
		}
		else
		{
			std::cout << "Index " << std::to_string(min) << " " << std::to_string(max) << "out of range \n";
		}
	}
}

void Container::addFibonnacci(unsigned start)
{
	Fibonnacci * obj = new Fibonnacci(start);
	sequences.push_back(obj);
}

void Container::addLucas(unsigned start)
{
	Pell * obj = new Pell(start);
	sequences.push_back(obj);
}

void Container::addPell(unsigned start)
{
	Pell * obj = new Pell(start);
	sequences.push_back(obj);
}

void Container::addPentagonal(unsigned start) 
{
	Pentagonal * obj = new Pentagonal(start);
	sequences.push_back(obj);
}

void Container::addQuadrados(unsigned start)
{
	Quadrados * obj = new Quadrados(start);
	sequences.push_back(obj);
}

void Container::addTriangular(unsigned start)
{
	Triangular * obj = new Triangular(start);
	sequences.push_back(obj);
}
