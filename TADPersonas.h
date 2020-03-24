#ifndef TADPERSONAS_H_INCLUDED
#define TADPERSONAS_H_INCLUDED
using namespace std;
class Persona
{
public:
    Persona();
    Persona(string n, string a, string c, string ci, string d,float t);
    string getNombre();
    string getApellidos();
    string getDireccion();
    string getCiudad();
    string getCedula();
    float getTelefono();
    void setNombre(string name);
    void setApellidos(string ap);
    void setCedula(string c);
    void setDireccion(string d);
    void setCiudad(string c);
    void setTelefono(float t);
    bool operator == (const Persona& param);
    bool operator != (const Persona& param);
    bool vacio();

protected:
    string nombre;
    string apellidos;
    string cedula;
    string direccion;
    string ciudad;
    float telefono;
};
#include "TADPersonas.hxx"
#endif // TADPERSONAS_H_INCLUDED
