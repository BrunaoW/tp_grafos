#include "Grafos.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

Grafo::Grafo(int n) {
	numVertices = n;
	int i, j;

	for (i = 0; i < n; i++) {
		vector<int> vetorAuxiliar;
		for (j = 0; j < n; j++) {
			vetorAuxiliar.push_back(0);
		}
		matrizAdj.push_back(vetorAuxiliar);
	}
}

Grafo::~Grafo() {
}

bool Grafo::inserirAresta(int v, int w) {
	if (matrizAdj[v][w] == 0) {
		matrizAdj[v][w] = 1;
		matrizAdj[w][v] = 1;
		numArestas++;
		return true;
	}

	return false;
}

bool Grafo::removerAresta(int v, int w) {
	if (matrizAdj[v][w] != 0) {
		matrizAdj[v][w] = 0;
		matrizAdj[w][v] = 0;
		numArestas--;
		return true;
	}

	return false;
}

int Grafo::obterNumeroDeArestas() {
	return numArestas;
}

int Grafo::obterNumeroDeVertices() {
	return numVertices;
}

bool Grafo::verificarExistenciaDeAresta(int v, int w) {
	if (matrizAdj[v][w] == 1)
		return true;
	else
		return false;
}

void Grafo::imprimirMatrizAdj() {
	int i, j;
	for (i = 0; i < numVertices; i++) {
		for (j = 0; j < numVertices; j++) {
			cout << matrizAdj[i][j] << " ";
		}
		cout << endl;
	}
}

bool Grafo::verificarGrafoCompleto() {
	int i, j;
	for (i = 0; i < numVertices - 1; i++) {
		for (j = i + 1; j < numVertices; j++) {
			if (matrizAdj[i][j] == 0)
				return false;
		}
	}

	return true;
}

void Grafo::completarGrafo() {
	int i, j;
	for (i = 0; i < numVertices - 1; i++) {
		for (j = i + 1; j < numVertices; j++) {
			if (matrizAdj[i][j] == 0) {
				inserirAresta(i, j);
			}
		}
	}
}

void Grafo::buscaEmLargura(int verticeInicial) {
	queue<int> filaDeVisita;
	vector<bool> visitados;

	for (int i = 0; i < numVertices; i++) {
		visitados.push_back(false);
	}

	cout << "Visitando vertice " << verticeInicial << endl;
	visitados[verticeInicial] = true;
	filaDeVisita.push(verticeInicial);

	while (!filaDeVisita.empty()) {
		int verticeAtual = filaDeVisita.front();
		filaDeVisita.pop();

		for (int verticeVisitado = 0; verticeVisitado < numVertices; verticeVisitado++) {
			if (verticeAtual != verticeVisitado && matrizAdj[verticeAtual][verticeVisitado] == 1 && !visitados[verticeVisitado]) {
				cout << "Visitando vertice " << verticeVisitado << endl;
				visitados[verticeVisitado] = true;
				filaDeVisita.push(verticeVisitado);
			}
		}
	}
}
