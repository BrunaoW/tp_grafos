#include "Lucas.h"

// Static member declaration
std::vector<unsigned long int> Lucas::sequence;

Lucas::Lucas()
{
	seq_size = 0;
	seq_type = "Lucas";

}

Lucas::Lucas(unsigned x)
{
	seq_size = x;
	gen_elems(x);
	seq_type = "Lucas";

}

// Index starts at 1.
unsigned long int Lucas::elem(int i)
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

void Lucas::print(std::ostream& os)
{
	for (int i = 0; i < sequence.size(); i++)
		os << std::to_string(sequence.at(i)) << " ";

	os << "\n";
}
int Lucas::length()
{
	//return (int) sequence.size();
	return (int)seq_size;
}

void Lucas::gen_elems(int i)
{
	int start = (int)sequence.size() + 1;
	for (int j = start; j <= i; j++)
	{
		unsigned long int fib_j = compute_element(j);
		sequence.push_back(fib_j);
	}

	if (i > seq_size) seq_size = i;
}

unsigned long int Lucas::compute_element(unsigned value)
{
	if (value == 1) return 1;
	else if (value == 2) return 3;

	value--;
	return sequence[value - 1] + sequence[value - 2];
}

