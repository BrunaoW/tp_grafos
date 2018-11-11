#pragma once

#pragma once
#include "Seq.h"

class Lucas : public Seq
{
private:
	static std::vector<unsigned long int> sequence;
	virtual void gen_elems(int i);
	unsigned long int compute_element(unsigned value);

public:
	Lucas();
	Lucas(unsigned x);
	virtual unsigned long int elem(int i);
	virtual void print(std::ostream& os);
	virtual int length();

};