#include "Grafos.h"

#include <iostream>

using namespace std;

int main() {
	Grafo g1(5);

	g1.inserirAresta(3, 1);
	g1.inserirAresta(2, 4);

	g1.imprimirMatrizAdj();

	if (g1.verificarGrafoCompleto())
		cout << "Grafo Completo" << endl;
	else
		cout << "Grafo Incompleto" << endl;

	g1.completarGrafo();

	g1.imprimirMatrizAdj();

	system("pause");

	return 0;
}
