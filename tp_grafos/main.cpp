#include "Grafos.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "Lendo quantidade de vertices e preenchendo as arestas listadas no arquivo..." << endl;
	
	fstream arquivo("Input.txt", ios_base::in);
	int numeroArestas, vertice1, vertice2;

	if (arquivo.is_open()) {
		arquivo >> numeroArestas;
		Grafo graph(numeroArestas);
		while (arquivo >> vertice1 >> vertice2) {
			graph.inserirAresta(vertice1, vertice2);
		}

		graph.imprimirMatrizAdj();
		graph.buscaEmLargura(0);
		graph.buscaEmProfundidade(0);
		graph.buscaMenorCaminhoDjikstra(0);
	}

	system("pause");

	return 0;
}
