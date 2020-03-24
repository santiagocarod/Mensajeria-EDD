#ifndef TADGRAFO_HXX_INCLUDED
#define TADGRAFO_HXX_INCLUDED
#define INF 200000
#include <bits/stdc++.h>
#include "TADGrafo.h"
using namespace std;

template<class T,class M>
Grafo<T,M>::Grafo()
{
	mat==NULL;
}

template<class T,class M>
bool Grafo<T,M>::esVacio()
{
	return (mat==NULL && vertices.empty());
}

template<class T,class M>
int Grafo<T,M>::cantidadVertice()
{
	int tam;
	if(esVacio())
	{
		tam=0;
	}
	else
	{
		tam=vertices.size();
	}
	return tam;
}

template<class T,class M>
int Grafo<T,M>::cantidadArista()
{
	int retu=0, tam=vertices.size();
	if(!esVacio())
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tam; j++)
			{
				if(mat[i][j]!=0)
				{
					retu++;
				}
			}

		}

	}

	return retu;
}

template<class T,class M>
int Grafo<T,M>::indiceVertice(T vertice)
{
	int r=-1;
	for(int i=0; i<vertices.size(); i++)
	{
		if(vertices[i]==vertice)
		{
			r=i;
		}
	}
	return r;
}
template<class T,class M>
vector<T> Grafo<T,M>:: getVertices()
{
	return vertices;
}

template<class T,class M>
bool Grafo<T,M>::insertarVertice(T vert)
{
	bool retu=false;
	int tam=vertices.size();
	M **copia=new M *[tam+1];
	M **a;
	for(int i=0; i<tam+1; i++)
	{
		copia[i]=new M[tam+1];
	}

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			copia[i][j]=mat[i][j];
		}

	}
	for(int i=0; i<tam+1; i++)
	{
		copia[i][tam]=0;
		copia[tam][i]=0;
	}
	vertices.push_back(vert);
	a=mat;
	mat=copia;
	for(int i=0; i<tam; i++)
	{
		delete a[i];
	}
	//delete[] a;

	return retu;
}

template<class T,class M>
bool Grafo<T,M>::insertarArista(T d, T o, M peso)
{
	bool retu=false;
	if(!esVacio())
	{
		if(!(buscarVertice(d) && buscarVertice(o)))
		{
			retu=false;
		}
		else
		{
			int id,od;
			id=indiceVertice(d);
			od=indiceVertice(o);
			mat[id][od]=peso;
			retu=true;
		}
	}

	return retu;
}

template<class T,class M>
bool Grafo<T,M>::eliminarVertice(T vert)
{
	bool retu=false;
	if(buscarVertice(vert))
	{
		int tam=vertices.size();
		M **copia=new M *[tam-1];
		for(int i=0; i<tam-1; i++)
		{
			copia[i]=new M[tam-1];

		}
		int indice=indiceVertice(vert);

		if((!esVacio()) && (indice!=-1))
		{
			for(int i=0; i<tam-1; i++)
			{
				for(int j=0; j<tam-1; j++)
				{
					if(i!=indice&&j!=indice)
					{
						copia[i][j]=mat[i][j];
					}
				}
			}
		}
		mat=copia;
		vertices.erase(vertices.begin()+indice);
	}
	else
	{
		cout<<"VERTICE NO ENCONTRADO"<<endl;
	}
	return retu;
}

template<class T,class M>
bool Grafo<T,M>::eliminarArista(T d,T o)
{
	bool retu=false;
	if(buscarVertice(d)&&buscarVertice(o))
	{
		if(!esVacio())
		{
			if(!(buscarVertice(d) && buscarVertice(o)))
			{
				retu=false;
			}
			else
			{
				int id,od;
				id=indiceVertice(d);
				od=indiceVertice(o);
				mat[id][od]=0;
				retu=true;
			}
		}
	}
	else
	{
		cout<<"ALGUN VERTICE NO FUE ENCONTRADO"<<endl;
	}

	return retu;
}

template<class T,class M>
bool Grafo<T,M>::buscarVertice(T vert)
{
	bool retu=false;
	int tam=vertices.size();
	if(!esVacio())

		for(int i=0; i<tam; i++)
		{
			if(vertices[i]==vert)
			{
				retu=true;
			}
		}
	return retu;
}

template<class T,class M>
T Grafo<T,M>::GetVertex(int vert)
{
	T retu;
	if(!(vert>= cantidadVertice()))
	{
		retu=vertices[vert];
	}
	return retu;
}


template<class T,class M>
bool Grafo<T,M>::buscarArista(T d, T o)
{
	bool retu=false;
	int dest=indiceVertice(d), ori=indiceVertice(o);
	if(!esVacio() && (dest!=-1 && ori!=-1))
	{
		if(mat[d][o]!=0)
			retu=true;
	}
	return retu;
}

template<class T,class M>
bool Grafo<T,M>::buscarVisitado(T vert)
{
	bool retu=false;
	for(int i=0; i<visitados.size(); i++)
	{
		if(vert==visitados[i])
			retu=true;
	}
	return retu;
}

template<class T,class M>
vector<T> Grafo<T,M>::profundidad(T vert)
{
	visitados.clear();
	stack<T> pila;
	vector<T> retu;
	if(!esVacio())
	{
		pila.push(vert);
		while(pila.size()!=0)
		{
			T aux=pila.top();
			pila.pop();
			if(!buscarVisitado(aux))
			{
				visitados.push_back(aux);
				retu.push_back(aux);
				vector<T> conex=obtenerConex(aux);
				for(int j=0; j<conex.size(); j++)
				{
					pila.push(conex[j]);
				}
			}

		}
	}
	return retu;
}

template<class T,class M>
vector<T> Grafo<T,M>::profundidadInv(T vert)
{
	int tam=cantidadVertice();
	int **copia=new int *[tam];
	for(int i=0; i<tam; i++)
	{
		copia[i]=new int[tam];

	}

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			copia[i][j]=mat[j][i];
		}
	}


	visitados.clear();
	stack<T> pila;
	vector<T> retu;
	if(!esVacio())
	{
		pila.push(vert);
		while(pila.size()!=0)
		{
			T aux=pila.top();
			pila.pop();
			if(!buscarVisitado(aux))
			{
				visitados.push_back(aux);
				retu.push_back(aux);
				vector<T> conex=obtenerConexInv(copia,aux);
				for(int j=0; j<conex.size(); j++)
				{
					pila.push(conex[j]);
				}
			}

		}
	}
	return retu;
}

template<class T,class M>
vector<pair<T,M> > Grafo<T,M>:: obtenerConexPeso(T vert)
{
	vector<pair<T,M> > retu;
	if(!esVacio())
	{
		int a=indiceVertice(vert);

		for(int i=0; i<vertices.size(); i++)
		{
			if(mat[a][i]!=0)
			{
				pair<T,M> par(vertices[i],mat[a][i]);
				retu.push_back(par);
			}

		}
	}

	return retu;

}

template<class T,class M>
vector<T> Grafo<T,M>:: obtenerConex(T vert)
{
	vector<T> retu;
	if(!esVacio())
	{
		int a=indiceVertice(vert);
		if(a!=-1)
		{
			for(int i=0; i<vertices.size(); i++)
			{
				if(mat[a][i]!=0)
					retu.push_back(vertices[i]);
			}
		}
	}

	return retu;

}

template<class T,class M>
vector<T> Grafo<T,M>:: obtenerConexInv(M ** inv,T vert)
{
	vector<T> retu;
	if(!esVacio())
	{
		int a=indiceVertice(vert);

		for(int i=0; i<vertices.size(); i++)
		{
			if(inv[a][i]!=0)
				retu.push_back(vertices[i]);
		}
	}

	return retu;

}

template<class T,class M>
std::vector<T> Grafo<T,M>::anchura(T vert)
{
	visitados.clear();
	queue<T> pila;
	vector<T> retu;
	if(!esVacio())
	{
		pila.push(vert);
		retu.push_back(vert);
		visitados.push_back(vert);
		while(pila.size()!=0)
		{
			T aux=pila.front();
			pila.pop();
			if(!buscarVisitado(aux))
			{
				visitados.push_back(aux);
				retu.push_back(aux);
				vector<T> conex=obtenerConex(aux);
				for(int j=0; j<conex.size(); j++)
				{
					pila.push(conex[j]);
				}
			}

		}
	}
}

template<class T,class M>
void aristasPuente()
{

}


template<class T,class M>
vector<int> Grafo<T,M>::caminoEuler(T vert)
{
	vector<int> camino;
	vector<int> vertimpares;
	int tam=vertices.size();
	int cantimpar = 0;
	for(int i=0; i<tam; i++)
	{
		int gradovert = 0;
		for(int j=0; j<tam; j++)
		{
			if(mat[i][j] != 0)
			{
				gradovert++;
			}
		}
		if((gradovert % 2) != 0)
		{
			cantimpar++;
			vertimpares.push_back(i);
		}
	}
	if(cantimpar > 2)
	{
		cout<<"No hay camino de Euler en el grafo";
		return camino;
	}
}

template<class T,class M>
void Grafo<T,M>::imprimirMatriz()
{
	int tam=vertices.size();
	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}


template<class T,class M>
int Grafo<T,M>::componentesConectados()
{
	vector<T> verts=vertices;
	int i;
	for(i=0; i<verts.size(); i++)
	{
		T dato=verts[i];
		vector<T> desce= profundidad(dato);
		for(int c=0; c<desce.size(); c++)
		{
			cout<<"Desce "<<i <<"  "<<desce[c]<<"  ";
		}
		vector<T> desceInv=profundidadInv(dato);
		for(int c=0; c<desceInv.size(); c++)
		{
			cout<<"DesceInv "<<i <<"  "<<desceInv[c]<<"  ";
		}
		vector<T> inter;
		set_intersection(desce.begin(),desce.end(),desceInv.begin(),desceInv.end(),back_inserter(inter));
		for(int c=0; c<inter.size(); c++)
		{
			cout<<"Interseccion "<<i <<"  "<<inter[c]<<"  ";
		}
		cout<<endl;
		for(int a=0; a<inter.size(); a++)
		{
			for(int b=0; b<verts.size(); b++)
			{
				if(inter[a]==verts[b])
				{
					verts.erase(verts.begin()+b);
				}
			}
		}
	}
	return i;
}

template<class T,class M>
M ** Grafo<T,M>::invertirMatriz(M** matriz)
{
	int tam=cantidadVertice();

	M **copia=new M *[tam];
	for(int i=0; i<tam; i++)
	{
		copia[i]=new M[tam];
	}

	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			copia[i][j]=mat[j][i];
		}
	}
	return copia;
}

template<class T,class M>
vector<pair<T,T> > Grafo<T,M>::Prim(T vert)
{
	vector<pair<T,T>  > retu;
	vector<pair<T,M>  >veci;
	vector<T>vis;
	vis.push_back(vert);
	while(!vectorIgual(vis,vertices))
	{
		M mi=100000;
		pair<T,T> aux;
		pair<T,M>  aux2;
		for(int i=0; i<vis.size(); i++)
		{
			veci=obtenerConexPeso(vis[i]);
			for(int j=0; j<veci.size(); j++)
			{
				aux2=veci[i];
				if(aux2.second<min)
				{
					aux.first=vis[i];
					aux.second=aux2.first;
					min=aux2.second;
				}
			}

		}
		retu.push_back(aux);
	}

	return retu;

}

template<class T,class M>
vector<vector<M> > Grafo<T,M>::Dikjstra(T vert)
{
	vector<vector<M> > retorno;
	retorno.clear();
	visitados.clear();
	int indice;
	vector<M> retu;
	vector<M> pred;
	for(int i=0; i<vertices.size(); i++)
	{
		retu.push_back(INF);
		pred.push_back(-1);
	}
	priority_queue<pair<M,M>, vector<pair<M,M> >, compa<M> > cola;

	if(buscarVertice(vert))
	{

		indice=indiceVertice(vert);
		//cout<<"INDICE: "<<indice<<endl;
		retu[indice]=0;
		pred[indice]=indice;
		pair<M,M> aux(indice,retu[indice]);
		cola.push(aux);

		while(!cola.empty())
		{
			//cout<<"SIZE: "<<cola.size()<<"\t";
			pair<M,M> a=cola.top();
			indice=a.first;
			//cout<<a.first<<endl;
			visitados.push_back(vertices[a.first]);
			cola.pop();
			vector<pair<T,M> > v= obtenerConexPeso(vertices[a.first]);
			for(int i=0; i<v.size(); i++)
			{
				if(!buscarVisitado(v[i].first))
				{
					pair<M,M> aux(indiceVertice(v[i].first),retu[indiceVertice(v[i].first)]);
					cola.push(aux);
				}

			}
			for(int i=0; i<v.size(); i++)
			{
				int ind=indiceVertice(v[i].first);
				//			cout<<"INDICE 1: "<<indice;
				//		cout<<"   INDICE 2: "<<ind<<endl;
				if(retu[ind]> retu[indice]+v[i].second)
				{
					retu[ind]= retu[indice]+v[i].second;
					pred[ind]=indice;

				}

			}


		}
		retorno.push_back(retu);
		retorno.push_back(pred);
		return retorno;
	}



}

template<class T,class M>
bool Grafo<T,M>::vectorIgual(vector<T> v1,vector<T> v2)
{
	bool retu=false,enc=false;
	int c=0;
	if(v1.size()==v2.size())
	{
		for(int i=0; i<v1.size(); i++)
		{
			enc=false;
			for(int j=0; j<v2.size() &&!enc; j++)
			{
				if(v1[i]==v2[j])
				{
					enc=true;
				}
			}
			if(enc)
				c++;
		}
		if(c==v1.size())
			retu=true;
	}
	return retu;
}

template<class T,class M>
bool Grafo<T,M>::estaVector(T vert, vector<T> vis)
{
	bool retu=false;
	for(int i=0; i<vis.size(); i++)
	{
		if(vis[i]==vert)
		{
			retu=true;
		}
	}
	return retu;
}
template<class T,class M>
vector<M**> Grafo<T,M> :: floydWarshall()
{
	vector<M**> v;
	int tam=vertices.size();
	M **path=new M *[tam];
	T **pred=new M *[tam];
	for(int i=0; i<tam; i++)
	{
		path[i]=new M[tam];
		pred[i]=new M[tam];


	}
	for(int i=0; i<vertices.size(); i++)
	{

		for(int j=0; j<vertices.size(); j++)
		{
			if(mat[i][j]==0 && i!=j)
			{
				path[i][j]=INF;
			}
			else
				path[i][j]=mat[i][j];

			if(mat[i][j]<INF && i!=j && mat[i][j]!=0)
			{
				pred[i][j]=i;
			}
			else
				pred[i][j]=-1;



		}
	}
	for(int k = 0; k < vertices.size(); k++)
		for(int i = 0; i < vertices.size(); i++)
			for(int j = 0; j < vertices.size(); j++)
			{
				int dt = path[i][k] + path[k][j];
				if(path[i][j] > dt)
				{
					path[i][j] = dt;
					pred[i][j]=pred[k][j];
				}

			}
	v.push_back(path);
	v.push_back(pred);
	return v;
}
template<class T,class M>
T Grafo<T,M>:: buscarVerticeCod(T vert)
{
	T retu;
	bool a=false;
	int tam=cantidadVertice();
	if(!esVacio())
		for(int i=0; i<tam; i++)
		{
			if(vertices[i]==vert)
			{
				retu=vertices[i];
				a=true;
			}
		}
	if(!a)
		retu=T(false);
	return retu;
}
template<class T,class M>
void Grafo<T,M>::setVertices(vector<T> vert){
	vertices=vert;
}
template<class T,class M>
M Grafo<T,M>::getPeso(int indDesde,int indHasta){
	if((indDesde<=cantidadVertice())&&(indHasta<=cantidadVertice()))
	{
		return mat[indDesde][indHasta];
	}
	else{
		return -1;
	}
}
#endif
