#include "Fibonnacci.h"

// Static member declaration
std::vector<unsigned long int> Fibonnacci::sequence;

Fibonnacci::Fibonnacci()
{

}

// Index starts at 1.
unsigned long int Fibonnacci::elem(int i)
{
	if (i < 1)
	{
		return -1;
	}

	if (i > sequence.size())
	{
		gen_elems(i);
	}

	return sequence.at(i-1);
}

void Fibonnacci::print(std::ostream& os)
{
	for (int i = 0; i < sequence.size(); i++)
		os << std::to_string(sequence.at(i)) << " ";

	os << "\n";
}
int Fibonnacci::length()
{
	return (int) sequence.size();
}

void Fibonnacci::gen_elems(int i)
{
	int start = (int) sequence.size() + 1;
	for (int j = start; j <= i; j++)
	{
		unsigned long int fib_j = fib(j);
		sequence.push_back(fib_j);
	}
}

unsigned long int Fibonnacci::fib(unsigned value)
{
	if (value == 1 || value == 2) return 1;
	return sequence[value - 2] + sequence[value - 3];
}