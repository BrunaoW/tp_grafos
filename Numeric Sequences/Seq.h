#pragma once
#include <vector>
#include <ostream>
#include <string>

// Seq: Sequence base class (interface)

class Seq
{
protected: 
	unsigned seq_size;
	virtual void gen_elems(int i) = 0;

public: 
	virtual unsigned long int elem(int i) = 0 ; 
	virtual void print(std::ostream& os) = 0;
	virtual int length() = 0;
};

std::ostream& operator<< (std::ostream& stream, Seq& obj);