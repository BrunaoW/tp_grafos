#pragma once
#include <vector>
#include <iostream>
#include "Seq.h"
#include "Fibonnacci.h"
#include "Lucas.h"
#include "Pell.h"
#include "Pentagonal.h"
#include "Quadrados.h"
#include "Triangular.h"

class Container
{
private:
	std::vector<Seq *> sequences;
	void printAny(Seq & obj, int min, int max);
public: 
	void printSequences();
	void printSequences(unsigned index);
	void printSequences(unsigned i, unsigned j);

	void addFibonnacci(unsigned start);
	void addLucas(unsigned start);
	void addPell(unsigned start);
	void addPentagonal(unsigned start);
	void addQuadrados(unsigned start);
	void addTriangular(unsigned start);
};