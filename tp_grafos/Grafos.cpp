#include "Grafos.h"

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

Grafo::Grafo(int n) {
	_numVertices = n;
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
		_numArestas++;
		_grafoPercorrido = false;
		return true;
	}

	return false;
}

bool Grafo::removerAresta(int v, int w) {
	if (matrizAdj[v][w] != 0) {
		matrizAdj[v][w] = 0;
		matrizAdj[w][v] = 0;
		_numArestas--;
		_grafoPercorrido = false;
		return true;
	}

	return false;
}

int Grafo::obterNumeroDeArestas() {
	return _numArestas;
}

int Grafo::obterNumeroDeVertices() {
	return _numVertices;
}

bool Grafo::verificarExistenciaDeAresta(int v, int w) {
	if (matrizAdj[v][w] == 1)
		return true;
	else
		return false;
}

void Grafo::imprimirMatrizAdj() {
	int i, j;
	for (i = 0; i < _numVertices; i++) {
		for (j = 0; j < _numVertices; j++) {
			cout << matrizAdj[i][j] << " ";
		}
		cout << endl;
	}
}

bool Grafo::verificarGrafoCompleto() {
	int i, j;
	for (i = 0; i < _numVertices - 1; i++) {
		for (j = i + 1; j < _numVertices; j++) {
			if (matrizAdj[i][j] == 0)
				return false;
		}
	}

	return true;
}

void Grafo::completarGrafo() {
	int i, j;
	for (i = 0; i < _numVertices - 1; i++) {
		for (j = i + 1; j < _numVertices; j++) {
			if (matrizAdj[i][j] == 0) {
				inserirAresta(i, j);
			}
		}
	}
}

void Grafo::buscaEmLargura(int verticeInicial) {
	cout << "Esta eh a rotina de busca em largura" << endl;

	queue<int> filaDeVisita;
	vector<bool> visitados;

	for (int i = 0; i < _numVertices; i++) {
		visitados.push_back(false);
	}

	cout << "Visitando vertice " << verticeInicial << endl;
	visitados[verticeInicial] = true;
	filaDeVisita.push(verticeInicial);

	while (!filaDeVisita.empty()) {
		int verticeAtual = filaDeVisita.front();
		filaDeVisita.pop();

		for (int verticeVisitado = 0; verticeVisitado < _numVertices; verticeVisitado++) {
			if (verticeAtual != verticeVisitado && matrizAdj[verticeAtual][verticeVisitado] == 1 && !visitados[verticeVisitado]) {
				cout << "Visitando vertice " << verticeVisitado << endl;
				visitados[verticeVisitado] = true;
				filaDeVisita.push(verticeVisitado);
			}
		}
	}

	cout << endl;
}

void Grafo::buscaEmProfundidade(int verticeInicial) {
	cout << "Esta e a rotina de busca em profundidade" << endl;
	
	stack<int> pilhaDeVisita;
	vector<bool> visitados;

	for (int i = 0; i < _numVertices; i++) {
		visitados.push_back(false);
	}

	_componentesConectados = 0;
	int verticeAtual = verticeInicial;
	int verticeVisitado;

	while(true) {
		if (!visitados[verticeAtual]) {
			cout << "Visitando Vertice " << verticeAtual << endl;
			visitados[verticeAtual] = true;
			pilhaDeVisita.push(verticeAtual);
		}

		bool encontrouVerticeVizinho = false;

		for (verticeVisitado = 0; verticeVisitado < _numVertices; verticeVisitado++) {
			if (verticeAtual != verticeVisitado && matrizAdj[verticeAtual][verticeVisitado] == 1 && !visitados[verticeVisitado]) {
				encontrouVerticeVizinho = true;
				break;
			}
		}

		if (encontrouVerticeVizinho) {
			verticeAtual = verticeVisitado;
		}
		else {
			pilhaDeVisita.pop();
			_componentesConectados++;

			if (pilhaDeVisita.empty()) {
				cout << endl;
				break;
			}

			verticeAtual = pilhaDeVisita.top();
		}
	}

	if (_componentesConectados == 1)
		_componentesConectados--;
	_grafoPercorrido = true;
}

int Grafo::obterNumeroDeComponentesConectados() {
	if (_grafoPercorrido) {
		return _componentesConectados;
	}
	else {
		cout << "Grafo não percorrido ainda" << endl;
		return NULL;
	}
}

int procuraMenorDistanciaEntreVertices(float *distanciaVertices, bool *visitados, int numeroDeVertices) {
	int i, menor = -1;
	bool primeiro = true;

	for (i = 0; i < numeroDeVertices; i++) {
		if (distanciaVertices[i] >= 0 && !visitados[i]) {
			if (primeiro) {
				menor = i;
				primeiro = false;
			}
			else {
				if (distanciaVertices[menor] > distanciaVertices[i])
					menor = i;
			}
		}
	}
	return menor;
}

void Grafo::buscaMenorCaminhoDjikstra(int verticeInicial) {
	cout << "Esta eh a rotina de busca do grafo pelo menor caminho possivel. Nele eh considerado distancia como o grau de distancia de um vertice a outro" << endl;

	int i, numeroDeVertices, contador, indice, verticeMaisPerto;
	contador = numeroDeVertices = _numVertices;

	int *anterior = (int*)malloc(numeroDeVertices * sizeof(int));

	float *distancia = (float*)malloc(numeroDeVertices * sizeof(float));

	bool *visitados = (bool*)malloc(numeroDeVertices * sizeof(bool));

	for (i = 0; i < numeroDeVertices; i++) {
		anterior[i] = -1;
		distancia[i] = -1;
		visitados[i] = false;
	}
	distancia[verticeInicial] = 0;

	while (contador > 0) {
		verticeMaisPerto = procuraMenorDistanciaEntreVertices(distancia, visitados, numeroDeVertices);
		if (verticeMaisPerto == -1)
			break;

		visitados[verticeMaisPerto] = true;
		cout << "Visitando vertice " << verticeMaisPerto << endl;
		contador--;

		for (i = 0; i < numeroDeVertices; i++) {
			if (matrizAdj[verticeMaisPerto][i] == 1) {
				indice = i;
				if (distancia[indice] < 0) {
					distancia[indice] = distancia[verticeMaisPerto] + 1;
					anterior[indice] = verticeMaisPerto;
				}
				else {
					if (distancia[indice] > distancia[verticeMaisPerto] + 1) {
						distancia[indice] = distancia[verticeMaisPerto] + 1;
						anterior[indice] = verticeMaisPerto;
					}
				}
			}
		}
	}
}