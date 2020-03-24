#ifndef TADGRAFO_H_INCLUDED
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define TADGRAFO_H_INCLUDED
template<class M>
struct compa {
	bool operator()(const pair<int, M>& lhs, const pair<int, M>& rhs) const
	{
		return lhs.second < rhs.second;
	}
};

template<class T,class M>
class Grafo
{
protected:
vector<T> vertices;
M **mat;
vector<T>visitados;
public:
Grafo();
bool esVacio();
int cantidadVertice();
int cantidadArista();
int indiceVertice(T vertice);
bool insertarVertice(T vert);
bool insertarArista(T d, T o, M peso);
bool eliminarVertice(T vert);
bool eliminarArista(T d,T o);
bool buscarVertice(T vert);
T buscarVerticeCod(T vert);
T GetVertex(int vert);
bool buscarArista(T d, T o);
std::vector<T> profundidad(T vert);
std::vector<T> profundidadInv(T vert);
std::vector<T> anchura(T vert);
void imprimirMatriz();
int componentesConectados();
void aristasPuente();
vector<int> caminoEuler(T vert);
M** invertirMatriz(M** matriz);
bool buscarVisitado(T vert);
vector<T> obtenerConex(T vert);
vector<pair<T,M> > obtenerConexPeso(T vert);
vector<T> obtenerConexInv(M** inv,T vert);
vector<T> getVertices();
void setVertices(vector<T> vert);
vector<pair<T,T> > Prim(T vert);
bool vectorIgual(vector<T> v1,vector<T> v2);
bool estaVector(T vert, vector<T> vis);
vector<vector<M> > Dikjstra(T vert);
vector<M**> floydWarshall();
M getPeso(int indDesde,int indHasta);
};
#include "TADGrafo.hxx"
#endif
