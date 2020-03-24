#ifndef TADARBOL_HXX_INCLUDED
#define TADARBOL_HXX_INCLUDED
#include "TADNodo.h"
#include <vector>
#include <iostream>

template <class T>
Arbol<T>::Arbol()
{
	raiz=NULL;
}

template <class T>
Arbol<T>::Arbol(T val)
{
	Nodo<T>* nodo=new Nodo<T>;
	nodo->fijarDato(val);
	raiz=nodo;
}

template <class T>
Arbol<T>::Arbol::~Arbol()
{

}

template <class T>
bool Arbol<T>::esVacio()
{
	if(raiz==NULL)
	{
		return true;
	}
	return false;
}

template <class T>
Nodo<T>* Arbol<T>::obtenerRaiz()
{
	return raiz;
}

template <class T>
void Arbol<T>::fijarRaiz(Nodo<T>* nraiz)
{
	raiz=nraiz;
}

template <class T>
bool Arbol<T>::insertarNodo(T padre, T n)
{
	if(esVacio())
	{
		raiz=new Nodo<T>();
		raiz->fijarDato(n);
		return true;
	}
	else
	{
		Nodo<T>* nodo=buscarNodo(n,raiz);
		if(nodo==NULL)
		{
			Nodo<T>* nodo2=buscarNodo(padre,raiz);
			if(nodo2!=NULL)
			{
				nodo2->adicionarDesc(n);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}


}

template <class T>
bool Arbol<T>::eliminarNodo(T n)
{
	if(raiz->obtenerDato()==n)
	{
		delete raiz;
	}
	else
	{
		Nodo<T>* nodo=buscarPadre(n,raiz);
		if(nodo!=NULL)
		{
			nodo->eliminarDesc(n);
		}
		else
		{
			cout<<"EL NODO: "<< n<< " NO EXISTE, POR ESTO NO SE PUEDE BORRAR."<<endl;
		}
	}
}

template <class T>
Nodo<T>* Arbol<T>::buscarNodo(T n,Nodo<T>* nodo)
{
	return buscarNodo2(n,nodo,NULL);
}

template <class T>
Nodo<T>* Arbol<T>::buscarNodo2(T n,Nodo<T>* nodo,Nodo<T>* nodor)
{
	if(esVacio())
	{
		nodor=NULL;
	}
	else
	{

		if(n==raiz->obtenerDato())
		{
			//cout<<"ENTRO RAIZ \t"<<n<<"\t"<<raiz->obtenerDato()<<endl;
			return raiz;
		}


		vector<Nodo<T>*> desce= nodo->obtenerDesc();
		for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
		{
			Nodo<T>* subNod=*i;
			if(subNod->obtenerDato()==n)
			{
				nodor=subNod;
			}
			else
			{
				nodor=buscarNodo2(n,subNod,nodor);
			}
		}

	}

	return nodor;

}

template <class T>
Nodo<T>* Arbol<T>::buscarPadre(T n,Nodo<T>* nodo)
{
	return buscarPadre2(n,nodo,NULL);
}

template <class T>
Nodo<T>* Arbol<T>::buscarPadre2(T n,Nodo<T>* nodo,Nodo<T>* nodor)
{


	vector<Nodo<T>*> desce= nodo->obtenerDesc();
	for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
	{
		Nodo<T>* subNod=*i;
		if(subNod->obtenerDato()==n)
		{
			nodor=nodo;
		}
		else
		{
			nodor=buscarPadre2(n,subNod,nodor);
		}
	}
	return nodor;
}

template<class T>
void Arbol<T>::imprimirArbol(Nodo<T>* nodo)
{
	vector<Nodo<T>*> desce= nodo->obtenerDesc();
	cout<<nodo->obtenerDato()<<endl;
	for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
	{
		Nodo<T>* subNod=*i;
		imprimirArbol(subNod);
	}
}

template<class T>
unsigned int Arbol<T>::tamano(Nodo<T>* inicio)
{
	static int con=0;
	vector<Nodo<T>*> desce= inicio->obtenerDesc();
	con++;
	for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
	{
		Nodo<T>* subNod=*i;
		con=tamano(subNod);
	}
	return con;
}

template<class T>
void Arbol<T>::preOrden(Nodo<T>* inicio)
{
	vector<Nodo<T>*> desce= inicio->obtenerDesc();
	cout<<inicio->obtenerDato()<<",";
	for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
	{
		Nodo<T>* subNod=*i;
		preOrden(subNod);
	}
}

template<class T>
void Arbol<T>::posOrden(Nodo<T>* inicio)
{
	vector<Nodo<T>*> desce= inicio->obtenerDesc();
	for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
	{
		Nodo<T>* subNod=*i;
		posOrden(subNod);
	}
	cout<<inicio->obtenerDato()<<endl;
}

template<class T>
int Arbol<T>::altura(Nodo<T>* inicio)
{
	return altura2(inicio,0,0)-1;
}

template<class T>
int Arbol<T>::altura2(Nodo<T>* inicio,int con,int max)
{
	if(inicio==NULL)
	{
		return 0;
	}
	else
	{
		if(inicio->obtenerDesc().size()>0)
		{
			con++;

			if(con>max)
			{
				max=con;
			}
		}
		vector<Nodo<T>*> desce= inicio->obtenerDesc();
		for(typename vector<Nodo<T>*>::iterator i=desce.begin(); i!=desce.end(); i++)
		{
			Nodo<T>* subNod=*i;
			max=altura2(subNod,con,max);
		}
		return max;
	}

}

template<class T>
unsigned int Arbol<T>::tamano()
{
	return tamano(raiz);
}


#endif
