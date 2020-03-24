#ifndef TADNODO_H_INCLUDED
#include <vector>
#define TADNODO_H_INCLUDED


template< class T >
class Nodo {
protected:
T dato;
std::vector< Nodo<T>* > desc;
public:
Nodo();
~Nodo();
T obtenerDato();
void fijarDato(T val);
std::vector< Nodo<T>* > obtenerDesc();
void limpiarLista();
void adicionarDesc(T nval);
void eliminarDesc(T val);
void imprimirLista();
};

#include "TADNodo.hxx"
#endif //TADNODO_H_INCLUDED
