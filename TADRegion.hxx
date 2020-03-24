#ifndef TADREGION_HXX_INCLUDED
#define TADREGION_HXX_INCLUDED
#include "TADRegion.h"

void Region::setNombrer(string n)
{
	nombrer=n;
}
void Region::setCodigo(string c)
{
	codigo=c;
}
void Region::setConjunto(vector<Paquete> c)
{
	conjunto=c;
}
string Region::getNombrer()
{
	return nombrer;
}
string Region::getCodigo()
{
	return codigo;
}
vector<Paquete> Region::getConjunto()
{
	return conjunto;
}

void Region::agregarPaquete(Paquete p){
	if(!buscarPaquete(p))
		conjunto.push_back(p);
	else
		cout<<"Paquete ya existente"<<endl;
}
bool Region::buscarPaquete(Paquete p)
{
	for(unsigned int i=0; i< conjunto.size(); i++)
	{
		if(p.getGuia()==conjunto[i].getGuia())
			return true;
	}
	return false;
}

bool Region::operator==(const Region &other) const
{
	return this->codigo==other.codigo;
}

bool Region::operator!=(const Region &other) const
{
	return !(*this==other);
}

std::ostream& operator<< (std::ostream& stream, const Region& p)
{
	stream<< p.nombrer;
	return stream;
}
#endif // TADREGION_HXX_INCLUDED
