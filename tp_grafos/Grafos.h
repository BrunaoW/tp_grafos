#ifndef CLASSE_GRAFOS
#define CLASSE_GRAFOS

#include <vector>

using namespace std;

class Grafo {
	int _numVertices = 0;
	int _numArestas = 0;
	int _componentesConectados = 0;
	bool _grafoPercorrido = false;
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
	int obterNumeroDeComponentesConectados();
	void buscaMenorCaminhoDjikstra(int verticeInicial);
};

#endif