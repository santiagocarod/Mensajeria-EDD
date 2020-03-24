#ifndef TADARBOL_H_INCLUDED
#include <vector>
#include "TADNodo.h"
#define TADARBOL_H_INCLUDED

template <class T>
class Arbol {
protected:
Nodo<T>* raiz;
public:
Arbol();
Arbol(T val);
~Arbol();
bool esVacio();
Nodo<T>* obtenerRaiz();
void fijarRaiz(Nodo<T>* nraiz);
bool insertarNodo(T padre, T n);
bool eliminarNodo(T n);
Nodo<T>* buscarNodo2(T n, Nodo<T>* nodo,Nodo<T>* nodor);
Nodo<T>* buscarNodo(T n, Nodo<T>* nodo);
Nodo<T>* buscarPadre2(T n, Nodo<T>* nodo,Nodo<T>* nodor);
Nodo<T>* buscarPadre(T n, Nodo<T>* nodo);
void imprimirArbol(Nodo<T>* nodo);
unsigned int tamano(Nodo<T>* inicio);
unsigned int tamano();
//bool buscarDato(T& n);
int altura(Nodo<T>* inicio);
int altura2(Nodo<T>* inicio,int con,int max);
void preOrden(Nodo<T>* inicio);
void posOrden(Nodo<T>* inicio);
//void nivelOrden(Nodo<T>* inicio);
};

#include "TADArbol.hxx"
#endif //TADARBOL_H_INCLUDED
