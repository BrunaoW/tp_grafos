#include "Pell.h"

// Static member declaration
std::vector<unsigned long int> Pell::sequence;

Pell::Pell()
{
	seq_size = 0;
}

Pell::Pell(unsigned x)
{
	seq_size = x;
	gen_elems(x);
}

// Index starts at 1.
unsigned long int Pell::elem(int i)
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

void Pell::print(std::ostream& os)
{
	for (int i = 0; i < sequence.size(); i++)
		os << std::to_string(sequence.at(i)) << " ";

	os << "\n";
}
int Pell::length()
{
	//return (int) sequence.size();
	return (int)seq_size;
}

void Pell::gen_elems(int i)
{
	int start = (int)sequence.size() + 1;
	for (int j = start; j <= i; j++)
	{
		unsigned long int fib_j = compute_element(j);
		sequence.push_back(fib_j);
	}

	if (i > seq_size) seq_size = i;
}

unsigned long int Pell::compute_element(unsigned value)
{
	if (value == 1) return 1;
	else if (value == 2) return 3;

	value--; 
	return sequence[value - 1] + sequence[value - 2];
}

