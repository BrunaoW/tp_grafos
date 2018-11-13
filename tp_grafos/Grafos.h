#ifndef CLASSE_GRAFOS
#define CLASSE_GRAFOS

#include <vector>

using namespace std;

class Grafo {
	int numVertices;
	int numArestas;
	vector<vector<int>> matrizAdj;

	public:
	Grafo(int);
	~Grafo();
	bool inserirAresta(int v, int w);
	bool removerAresta(int v, int w);
	int obterNumeroDeArestas();
	int obterNumeroDeVertices();
	bool verificarExistenciaDeAresta(int v, int w);
	void imprimirMatrizAdj();
	bool verificarGrafoCompleto();
	void completarGrafo();
	void buscaEmLargura(int verticeInicial);
	void buscaEmProfundidade(int verticeInicial);
};

#endif