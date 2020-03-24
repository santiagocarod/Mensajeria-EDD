#ifndef TADNODO_HXX_INCLUDED
#define TADNODO_HXX_INCLUDED
#include "TADNodo.h"
#include <vector>
#include <iostream>

using namespace std;

template<class T>
Nodo<T>::Nodo(){
}

template<class T>
Nodo<T>::~Nodo(){
}

template<class T>
T Nodo<T>::obtenerDato(){
	return dato;
}

template<class T>
void Nodo<T>::fijarDato(T val){
	dato=val;
}

template<class T>
std::vector< Nodo<T>* > Nodo<T>::obtenerDesc(){
	return desc;
}

template<class T>
void Nodo<T>::limpiarLista(){
	desc.erase(desc.begin(),desc.end());
}

template<class T>
void Nodo<T>::adicionarDesc(T nval){
	Nodo<T>* nodo=new Nodo<T>;
	nodo->fijarDato(nval);
	desc.push_back(nodo);
}

template<class T>
void Nodo<T>::eliminarDesc(T val){
	vector<Nodo<T>*> nodos=obtenerDesc();
	typename vector<Nodo<T>*>::iterator it=desc.begin();
	for(auto i : nodos){
		Nodo<T>* nodo = i;
		if(nodo->obtenerDato()==val){
			desc.erase(it);
		}
		it++;
	}

}

template<class T>
void Nodo<T>::imprimirLista(){
	for(typename vector<Nodo<T>*>::iterator i=desc.begin(); i!=desc.end(); i++) {
		Nodo<T>* nod=*i;
		cout<<nod->dato;
	}
	cout<<endl;
}

#endif //TADNODO_HXX_INCLUDED
