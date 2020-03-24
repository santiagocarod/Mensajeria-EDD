#ifndef TADPAQUETE_H_INCLUDED
#define TADPAQUETE_H_INCLUDED
#include "TADPersonas.h"
class Paquete
{
public:
bool setRemitente(Persona r);
bool setDestinatario(Persona d);
void setPeso(float p);
void setContenido(string c);
void setGuia(string g);
Persona getRemitente();
Persona getDestinatario();
float getPeso();
string getContenido();
string getGuia();
bool operator==(const Paquete &other) const;
bool operator!=(const Paquete &other) const;
protected:
Persona remitente;
Persona destinatario;
float peso;
string contenido;
string guia;
};
#include "TADPaquete.hxx"
#endif // TADPAQUETE_H_INCLUDED
