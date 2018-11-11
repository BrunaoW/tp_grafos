#pragma once
#include "Seq.h"

class Fibonnacci : public Seq
{
private:
	static std::vector<unsigned long int> sequence;
	virtual void gen_elems(int i);
	unsigned long int fib(unsigned value);

public:
	Fibonnacci();
	virtual unsigned long int elem(int i);
	virtual void print(std::ostream& os);
	virtual int length();

};