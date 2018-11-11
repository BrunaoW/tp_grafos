#include "Grafos.h"

#include <iostream>

using namespace std;

int main() {
	Grafo g1(5);

	g1.inserirAresta(3, 1);
	g1.inserirAresta(2, 4);
	g1.inserirAresta(0, 1);
	g1.inserirAresta(0, 4);

	g1.imprimirMatrizAdj();

	g1.buscaEmLargura(2);

	system("pause");

	return 0;
}
