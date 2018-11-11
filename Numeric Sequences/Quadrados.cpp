#include "Quadrados.h"

// Static member declaration
std::vector<unsigned long int> Quadrados::sequence;

Quadrados::Quadrados()
{
	seq_size = 0;
}

Quadrados::Quadrados(unsigned x)
{
	seq_size = x;
	gen_elems(x);
}

// Index starts at 1.
unsigned long int Quadrados::elem(int i)
{
	if (i < 1)
	{
		return -1;
	}

	if (i > sequence.size())
	{
		gen_elems(i);
	}

	return sequence.at(i - 1);
}

void Quadrados::print(std::ostream& os)
{
	for (int i = 0; i < sequence.size(); i++)
		os << std::to_string(sequence.at(i)) << " ";

	os << "\n";
}
int Quadrados::length()
{
	//return (int) sequence.size();
	return (int)seq_size;
}

void Quadrados::gen_elems(int i)
{
	int start = (int)sequence.size() + 1;
	for (int j = start; j <= i; j++)
	{
		unsigned long int fib_j = compute_element(j);
		sequence.push_back(fib_j);
	}

	if (i > seq_size) seq_size = i;
}

unsigned long int Quadrados::compute_element(unsigned value)
{
	if (value == 1) return 1;

	value--;
	return (value + 1) * (value + 1);
}

