#ifndef TADOFICINA_HXX_INCLUDED
#define TADOFICINA_HXX_INCLUDED
#include "TADOficina.h"
#include <bits/stdc++.h>

Oficina :: Oficina(bool a)
{
	codofi="NO";
}


Oficina :: Oficina()
{

}
void Oficina::setRegiones(vector<Region> r)
{
	regiones=r;
}
void Oficina::setCodOfi(string c)
{
	codofi=c;
}
void Oficina::setNombreO(string n)
{
	nombreo=n;
}
void Oficina::setDireccionO(string d)
{
	direcciono=d;
}
void Oficina::setCiudadO(string ci)
{
	ciudado=ci;
}

vector<Region> Oficina::getRegiones()
{
	return regiones;
}
string Oficina::getCiudadO()
{
	return ciudado;
}
string Oficina::getCodOfi()
{
	return codofi;
}
string Oficina::getNombreO()
{
	return nombreo;
}
string Oficina::getDireccionO()
{
	return direcciono;
}
bool Oficina::agregarRegion(Region r)
{
	regiones.push_back(r);
	return true;
}

void Oficina::ingresarRegion(string codigoRegion,string nombreRegion, Paquete p)
{
	Region r;
	r.setCodigo(codigoRegion);
	r.setNombrer(nombreRegion);
	for(unsigned int i=0; i<regiones.size(); i++)
	{
		if(r==regiones[i])
		{
			regiones[i].agregarPaquete(p);
			return;
		}
	}

	r.agregarPaquete(p);
	agregarRegion(r);
}

bool Oficina::operator==(const Oficina &other) const
{
	return ((this->codofi==other.codofi));
}
bool Oficina::operator!=(const Oficina &other) const
{
	return !(other==*this);
}

std::ostream& operator<< (std::ostream& stream, const Oficina& p)
{
	stream<<p.nombreo<<" - "<< p.codofi;
	return stream;
}
#endif // TADOFICINA_HXX_INCLUDED
