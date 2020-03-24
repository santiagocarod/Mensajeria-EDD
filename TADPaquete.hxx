#ifndef TADPAQUETE_HXX_INCLUDED
#define TADPAQUETE_HXX_INCLUDED
#include "TADPaquete.h"
bool Paquete::setRemitente(Persona r)
{
    if(destinatario.vacio() || r!=destinatario)
    {
        remitente=r;
        return true;
    }
    else return false;



}
bool Paquete::setDestinatario(Persona d)
{
     if(remitente.vacio() || d!=remitente)
    {
        destinatario=d;
        return true;
    }
    else return false;
}
void Paquete::setPeso(float p)
{
    peso=p;
}
void Paquete::setContenido(string c)
{
    contenido=c;
}
void Paquete::setGuia(string g)
{
    guia=g;
}
Persona Paquete::getRemitente()
{
    return remitente;
}
Persona Paquete::getDestinatario()
{
    return destinatario;
}
float Paquete::getPeso()
{
    return peso;
}
string Paquete::getContenido()
{
    return contenido;
}
string Paquete::getGuia()
{
    return guia;
}
  bool Paquete::operator==(const Paquete &other) const
  {
      return this->guia==other.guia;
  }

  bool Paquete::operator!=(const Paquete &other) const
  {
      return !(*this==other);
  }

#endif // TADPAQUETE_HXX_INCLUDED
