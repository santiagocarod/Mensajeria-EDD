#ifndef TADREGION_H_INCLUDED
#define TADREGION_H_INCLUDED
#include "TADPaquete.h"
#include <vector>
class Region
{
public:
void setNombrer(string n);
void setCodigo(string c);
void setConjunto(vector<Paquete> c);
string getNombrer();
string getCodigo();
vector<Paquete> getConjunto();
void agregarPaquete(Paquete p);
bool buscarPaquete(Paquete p);
bool operator==(const Region &other) const;
bool operator!=(const Region &other) const;
friend std::ostream& operator<< (std::ostream& stream, const Region& p);
protected:
string nombrer;
string codigo;
vector<Paquete> conjunto;
};

#include "TADRegion.hxx"
#endif // TADREGION_H_INCLUDED
