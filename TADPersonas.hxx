#include "TADPersonas.h"
#ifndef TADPERSONAS_HXX_INCLUDED
#define TADPERSONAS_HXX_INCLUDED
Persona::Persona()
 {
     nombre="";
     apellidos="";
     cedula="";
     ciudad="";
     direccion="";
     telefono=-1;
 }
 Persona::Persona(string n, string a, string c, string ci, string d,float t)
 {
     nombre=n;
     apellidos=a;
     cedula=c;
     ciudad=ci;
     direccion=d;
     telefono=t;
 }
string Persona:: getNombre()
{
return nombre;
}
string Persona::getApellidos()
{
    return apellidos;
}
string Persona::getDireccion()
{
    return direccion;
}
string Persona::getCiudad()
{
    return ciudad;
}
string Persona::getCedula()
{
    return cedula;
}
float Persona::getTelefono()
{
    return telefono;
}
void Persona::setNombre(string name)
{
    nombre=name;
}
void Persona::setApellidos(string ap)
{
    apellidos=ap;
}
void Persona::setCedula(string c)
{
    cedula=c;
}
void Persona::setDireccion(string d)
{
    direccion=d;
}
void Persona::setCiudad(string c)
{
    ciudad=c;
}
void Persona::setTelefono(float t)
{
    telefono=t;
}
bool Persona::operator==(const Persona& param)
{
    if(this->cedula==param.cedula)
        return true;
    else
        return false;
}

bool Persona::operator!=(const Persona& param)
{
    if(this->cedula==param.cedula)
        return false;
    else
        return true;
}

bool Persona::vacio()
{
    if(nombre==""&& apellidos==""&&cedula=="" &&ciudad==""&& direccion==""&&telefono==-1) return true;
    else return false;
}
#endif // TADPERSONAS_HXX_INCLUDED
