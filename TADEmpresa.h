#ifndef TADEMPRESA_H_INCLUDED
#include "TADOficina.h"
#include "TADPersonas.h"
#include <vector>
#include "TADGrafo.h"
#define TADEMPRESA_H_INCLUDED
class Empresa
{
public:
void cargarPersonas(string na);
bool personaExiste(Persona p);
vector<Persona> getDirectorio();
void registrarPersona();
Persona buscarPersona(string ced);
void leerArchivoPaquetes(string archivo);
bool ingresarPaquete1(Paquete p,string codigoOficina,string codigoRegion);
bool buscarPaquete(string guia);
void conteoPaquetes();
void conteoPaquetes1();
bool sinPaquetes();
void ingresarPaquete();
inline bool isInteger(const std::string & s);
bool cargarRegiones(string ar);
int cargarOficinas(string of);
void registrarOficina();
void registrarRegion();
void repartirPaquetes(string cod);
bool sinOficinas();
string trim(const string& str);
void repartirPaquetes1(Oficina n);
vector<Oficina> getOficinas();
void setOficinas (vector<Oficina> ofi);
Oficina* buscarVecOfi(string cod);
void cargarConexiones(string nom);
void rutaReparto(string origen, string destino);

private:
vector<Persona> directorio;
Grafo<Oficina,float> red;
vector<string> regPaq;
vector<Oficina> oficinas;
};

#include "TADEmpresa.hxx"
#endif // TADEMPRESA_H_INCLUDED
