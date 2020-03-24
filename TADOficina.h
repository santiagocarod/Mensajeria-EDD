#ifndef TADOFICINA_H_INCLUDED
#define TADOFICINA_H_INCLUDED
#include "TADRegion.h"
class Oficina
{
public:
Oficina(bool a);
Oficina();
void setRegiones(vector<Region> r);
void setCodOfi(string c);
void setNombreO(string n);
void setDireccionO(string d);
void setCiudadO(string ci);
vector<Region> getRegiones();
string getCiudadO();
string getCodOfi();
string getNombreO();
string getDireccionO();
bool agregarRegion(Region r);
void ingresarRegion(string codigoRegion,string nombreRegion, Paquete p);
bool operator==(const Oficina &other) const;
bool operator!=(const Oficina &other) const;
friend std ::ostream& operator<< (std::ostream& stream, const Oficina& p);
protected:
vector<Region> regiones;
string codofi;
string nombreo;
string direcciono;
string ciudado;
};

#include "TADOficina.hxx"
#endif // TADOFICINA_H_INCLUDED
