#ifndef TADEMPRESA_HXX_INCLUDED
#define TADEMPRESA_HXX_INCLUDED
#define INF 200000
#include "TADEmpresa.h"
#include "TADPersonas.h"
#include "TADRegion.h"
#include <bits/stdc++.h>
using namespace std;

void Empresa::cargarPersonas(string na)
{
    ifstream arch;
    int ce=0,in=0;
    const char* nb= na.c_str();
    arch.open(nb,ios::in);
    if(!arch)
    {
        cout<<"(Archivo  no existe) El archivo "<<na<<" no existe o es ilegible."<<endl;
    }
    else
    {
        if(!arch.is_open())
        {
            cout<<"El archivo no se puede abrir"<<endl;
        }
        else
        {
            char entrada[400];
            arch.getline(entrada,400);

            while(!arch.eof())
            {
                arch.getline(entrada,400);
                char* aux;
                aux=strtok(entrada, ",");
                int i=0;
                string n,a,c,d,ci;
                while(aux!=NULL)
                {
                    if(i==0)
                        n=string(aux);
                    if(i==1)
                        a=string(aux);
                    if(i==2)
                        c=string(aux);
                    if(i==3)
                        d=string(aux);
                    if(i==4)
                        ci=string(aux);
                    if(i==5)
                    {
                        float t =(float)atof(aux);
                        Persona p(n,a,c,ci,d,t);
                        if(!personaExiste(p))
                        {
                            this->directorio.push_back(p);
                            ce++;
                        }
                        else
                            in++;

                    }

                    aux=strtok(NULL, ",");
                    i++;
                }
            }

        }
        arch.close();
        cout<<" Desde el archivo "<<na<<" , se han cargado exitosamente "<< ce <<" registros; mientras que "<<in<< " registros presentaron problemas "<<endl;

    }


}

bool Empresa::personaExiste(Persona p)
{
    if(directorio.empty())
        return false;
    for(unsigned int i=0; i<directorio.size(); i++)
    {
        if(p==directorio[i])
            return true;
    }
    return false;
}
vector<Persona> Empresa::getDirectorio()
{
    return directorio;
}
void Empresa::registrarPersona()
{
    string ci;
    char entrada[400];
    float t;
    cout<<" Ingrese Nombre"<<endl;
    cin.getline(entrada,100);
    string n(entrada);
    cout<<" Ingrese Apellidos"<<endl;
    cin.getline(entrada,100);
    string a(entrada);
    cout<<" Ingrese cedula"<<endl;
    cin.getline(entrada,100);
    string id(entrada);
    cout<<" Ingrese Direccion"<<endl;
    cin.getline(entrada,200);
    string d(entrada);
    cout<<" Ingrese Ciudad"<<endl;
    cin.getline(entrada,100);
    string c(entrada);
    cout<<" Ingrese telefono"<<endl;
    cin>>t;
    Persona p(n,a,id,c,d,t);
    if(!personaExiste(p))
    {
        directorio.push_back(p);
        cout<<"La persona con identificacion "<<id<<" ha sido registrada exitosamente."<<endl;
        cin.ignore();
        return;
    }
    cout<<"La persona con identificacion "<<id<<" ya se encuentra registrada en el sistema."<<endl;
    cin.ignore();
    return;
}
int hehe=0;
bool Empresa::ingresarPaquete1(Paquete p,string codigoOficina,string codigoRegion)
{
    Oficina a;
    bool retu=false;
    a.setCodOfi(codigoOficina);
    a=red.buscarVerticeCod(a);
    int indi=red.indiceVertice(a);
    if(indi==-1)
    {
        retu= false;
        hehe++;
        cout<<"Oficina no existe:"<<codigoOficina<<"."<<p.getGuia()<<"   "<<hehe<<endl;


    }

    else
    {
        vector<Region>reg=a.getRegiones();
        for(int i=0; i<reg.size(); i++)
        {
            if(reg[i].getCodigo()==codigoRegion)
            {
                reg[i].agregarPaquete(p);
                retu=true;
            }
        }
        if(!retu)
        {
            hehe++;
            cout<<"Region no existe:"<<codigoRegion<<"."<<p.getGuia()<<"   "<<hehe<<endl;
        }

        else
        {
            a.setRegiones(reg);
            vector<Oficina> of=red.getVertices();
            of[indi]=a;
            red.setVertices(of);
        }


    }

    return retu;
}

bool Empresa::buscarPaquete(string guia)
{
    bool res=false;
    for(int i=0; i<regPaq.size(); i++)
    {
        if(guia==regPaq[i])
            res=true;
    }
    return res;
}



void Empresa::leerArchivoPaquetes(string archivo)
{
    int c=0,in=0;
    if(directorio.size()==0)
    {
        cout<<"Para ingresar paquetes debe haber ingresado primero las personas."<<endl;
        return;
    }
    const char* nb=archivo.c_str();
    ifstream file(nb);
    string linea;
    vector<string> datos;
    int con =0;
    if (file.is_open())
    {
        while(!file.eof())
        {
            getline(file,linea);
            if(!linea.empty())
            {
                if(con!=0)
                {
                    datos.push_back(linea);
                }
                con++;
            }
        }
        string temp;
        vector<string> ve;
        Oficina o;
        for(vector<string>::iterator i=datos.begin(); i!=datos.end(); i++)
        {
            try
            {
                temp=*i;
                istringstream iss(temp);
                string token;
                while (getline(iss, token, ','))
                {
                    token.erase(remove(token.begin(),token.end(),' '),token.end());
                    ve.push_back(token);

                }

                string remitente=ve.at(0);
                string destinatario=ve.at(1);
                int peso=atoi(ve.at(2).c_str());
                string contenido=ve.at(3);
                string guia=ve.at(4);
                string codigoOficina=ve.at(5);
                string nombreOficina=ve.at(6);
                string codigoRegion=ve.at(9);

                if((remitente.empty()||destinatario.empty()||contenido.empty()||guia.empty()||codigoOficina.empty()||nombreOficina.empty()||codigoRegion.empty()))
                {
                    throw invalid_argument("PROBLEMA CON EL ARCHIVO");
                }
                if(!buscarPaquete(guia))
                {
                    Paquete paq;
                    paq.setPeso(peso);
                    paq.setContenido(contenido);
                    paq.setGuia(guia);
                    if(ingresarPaquete1( paq, codigoOficina,codigoRegion))
                    {
                        c++;
                        regPaq.push_back(guia);
                    }

                    else
                    {
                        in++;
                    }

                }
                else
                {
                    cout<<"Paquete repetido: "<<guia<<endl;
                    in++;
                }




                ve.clear();
            }
            catch(const std::invalid_argument& e)
            {
                cout<<e.what()<<endl;
                file.close();
                return;
            }
        }

    }
    else
    {
        cout<<"El archivo no existe"<<endl;
        file.close();
        return;
    }
    cout<<"Desde el archivo "<<archivo<<" , se han cargado exitosamente "<< c <<" registros; mientras que "<<in<< " registros presentaron problemas "<<endl;
    file.close();
}


void Empresa::conteoPaquetes()
{
    if(!sinPaquetes())
    {
        cout<<"Total: "<<regPaq.size()<<endl;
        conteoPaquetes1();

    }

    else
        cout<<"No existe informacion de paquetes registrada en el sistema."<<endl;
}

void Empresa::conteoPaquetes1()
{
    vector<Oficina> ofi=red.getVertices();
    int ofip=0;
    for(int i=0; i<ofi.size(); i++)
    {
        vector<Region> r=ofi[i].getRegiones();
        ofip=0;
        for(int j=0; j<r.size(); j++)
        {
            cout<<r[j].getConjunto().size()<<"\t Paquetes en la region "<<r[j].getNombrer()<<" en la "<<ofi[i]<<endl;
            ofip+=r[j].getConjunto().size();
        }
        cout<<ofip<<"\t Parcial Paquetes en:\t "<<ofi[i].getNombreO()<<endl;
    }
}

inline bool Empresa::isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}


void Empresa::ingresarPaquete()
{
    bool es=true;
    int peso;
    string tipoContenido;
    string numGuia;
    Persona rem,des;
    string cedulaRemitente,codigoOficina,codigoRegion;
    do
    {
        cout<<"INGRESE POR FAVOR CEDULA DE REMITENTE: "<<endl;

        cin>>cedulaRemitente;
        rem=buscarPersona(cedulaRemitente);
        if(rem.getCedula()=="")
            cout<<"Remitente no registra en nuestro directorio"<<endl;
    }
    while(rem.getCedula()=="");
    do
    {
        cout<<"INGRESE POR FAVOR CEDULA DE DESTINATARIO: "<<endl;
        string cedulaDestinatario;
        cin>>cedulaDestinatario;
        des=buscarPersona(cedulaDestinatario);
        if(cedulaRemitente.compare(cedulaDestinatario)==0)
        {
            cout<<"INGRESE UNA CEDULA DIFERENTE A LA DEL REMITENTE"<<endl;
        }
        else
        {
            if(des.getCedula()=="")
            {
                cout<<"Remitente no registra en nuestro directorio"<<endl;
                es=false;
            }
            else
                es=false;

        }
    }
    while(es);
    do
    {
        es=true;
        cout<<"INGRESE POR FAVOR PESO DEL PAQUETE: "<<endl;
        string ppeso;
        cin>>ppeso;
        if(isInteger(ppeso))
        {
            es=false;
            peso=atoi(ppeso.c_str());
        }
        else
        {
            cout<<"INGRESE UN VALOR NUMERICO POR FAVOR"<<endl;
        }
    }
    while (es);
    do
    {
        es=true;
        cout<<"INGRESE POR FAVOR TIPO DE CONTENIDO DEL PAQUETE: "<<endl;

        cin>>tipoContenido;
        if(!tipoContenido.empty())
        {
            es=false;
        }
    }
    while(es);
    do
    {
        es=true;
        cout<<"INGRESE POR FAVOR EL NUMERO DE GUIA (AAA###) DEL PAQUETE: "<<endl;
        cin>>numGuia;
        for(unsigned int i=0; i<numGuia.size(); i++)
        {
            if(isalpha(numGuia[i])&&!isdigit(numGuia[i]))
            {
                numGuia[i]=toupper(numGuia[i]);
            }
        }
        if(!buscarPaquete(numGuia))
        {
            if(isalpha(numGuia[0])&& !isdigit(numGuia[0]))
            {
                if(isalpha(numGuia[1])&& !isdigit(numGuia[1]))
                {
                    if(isalpha(numGuia[2])&& !isdigit(numGuia[2]))
                    {
                        if(isdigit(numGuia[3]))
                        {
                            if(isdigit(numGuia[4]))
                            {
                                if(isdigit(numGuia[5]))
                                {
                                    es=false;
                                    numGuia[0]=toupper(numGuia[0]);
                                    numGuia[1]=toupper(numGuia[1]);
                                    numGuia[2]=toupper(numGuia[2]);
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            cout<<"EL PAQUETE " <<numGuia<<" YA EXISTE"<<endl;
            return;
        }
        if(es)
        {
            cout<<"INGRESE LA GUIA EN EL FORMATO"<<endl;
        }
    }
    while(es);

    cout<<"INGRESE EL CODIGO DE LA OFICINA: "<<endl;
    cin>>codigoOficina;
    Oficina ofi;
    ofi.setCodOfi(codigoOficina);

    cout<<"INGRESE EL CODIGO DE LA REGION DENTRO DE LA OFICINA"<<endl;
    cin>>codigoRegion;
    bool en=false;
    ofi=red.buscarVerticeCod(ofi);
    if(ofi.getCodOfi()!="NO")
    {
        vector<Region> regiones=ofi.getRegiones();
        for(int i=0; i<regiones.size()&&!en; i++)
        {
            if(regiones[i].getCodigo()==codigoRegion)
            {
                en=true;
            }
        }

        if(!en)
        {
            cout<<"ESTA REGION NO EXISTE DENTRO DE LA OFICINA"<<endl;
            return;
        }

        regPaq.push_back(numGuia);
        Paquete paq;
        paq.setPeso(peso);
        paq.setGuia(numGuia);
        paq.setContenido(tipoContenido);
        if(ingresarPaquete1( paq, codigoOficina, codigoRegion))
        {
            cout<<"PAQUETE "<< numGuia<<" INGRESADO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<<"EL PAQUETE "<< numGuia<<" NO SE INGRESO CORRECTAMENTE"<<endl;
        }
    }
    else
        cout<<"OFICINA INEXISTENTE"<<endl;
cin.ignore();
}

Persona Empresa:: buscarPersona(string ced)
{
    for(unsigned int i=0; i<directorio.size(); i++)
    {
        if(directorio[i].getCedula()==ced)
        {
            return directorio[i];
        }
    }
    return Persona();
}

bool Empresa::sinPaquetes()
{
    return regPaq.size()==0;
}

bool Empresa::cargarRegiones(string ar)
{
    vector<Region> regiones;
    std::vector<int> peso;
    vector<string> CodOficinas;
    int r=0,c=0;
    const char* nb=ar.c_str();
    ifstream file(nb);
    string linea;
    string codigo,nombre,ofice;
    if(file.is_open())
    {
        getline(file,linea,',');
        getline(file,linea,',');
        getline(file,linea,',');
        getline(file,linea);
        while(!file.eof())
        {
            try
            {
                getline(file,linea,',');
                if(linea=="")
                {
                    break;
                }

                linea.erase(remove(linea.begin(),linea.end(),' '),linea.end());
                codigo=linea;
                getline(file,linea,',');
                linea.erase(remove(linea.begin(),linea.end(),' '),linea.end());
                nombre=linea;
                getline(file,linea,',');
                linea.erase(remove(linea.begin(),linea.end(),' '),linea.end());
                ofice=linea;
                getline(file,linea,'\n');
                linea.erase(remove(linea.begin(),linea.end(),' '),linea.end());
                peso.push_back(stoi(linea));
                Region re;
                if(codigo.empty()||nombre.empty()||ofice.empty())
                {
                    throw invalid_argument("PROBLEMA CON EL ARCHIVO");
                }
                re.setCodigo(codigo);
                re.setNombrer(nombre);
                regiones.push_back(re);
                CodOficinas.push_back(ofice);
            }
            catch(const std::invalid_argument& e)
            {
                cout<<e.what()<<endl;
                file.close();
                return false;
            }
        }


    }
    else
    {
        cout<<"ARCHIVO INEXISTENTE"<<endl;
    }
    file.close();


    Oficina a;
    bool auxiliar=true,boolean=false;
    for(int i=0; i< regiones.size(); i++)
    {
        boolean=false;
        a.setCodOfi(regiones[i].getCodigo());
        a.setNombreO("Oficina "+regiones[i].getNombrer());
        red.insertarVertice(a);
        Oficina b;
        string z=CodOficinas[i];
        z.erase(remove(z.begin(),z.end(),' '),z.end());
        b.setCodOfi(z);

        if(!red.buscarVertice(b))
        {
            for(int j=0; j<oficinas.size() &&!boolean; j++)
            {
                if (oficinas[j]==b)
                {
                    std::vector<Region> v=oficinas[j].getRegiones();
                    v.push_back(regiones[i]);
                    oficinas[j].setRegiones(v);
                    red.insertarVertice(oficinas[j]);
                    boolean=true;
                }

            }
        }
        else
        {
            int ind=red.indiceVertice(b);
            std::vector<Oficina> v1=red.getVertices();
            Oficina e= v1[ind];
            std::vector<Region> v=e.getRegiones();
            v.push_back(regiones[i]);
            e.setRegiones(v);
            v1[ind]=e;
            red.setVertices(v1);
        }
        b=red.buscarVerticeCod(b);
        if(!(red.insertarArista(a,b,peso[i])&&red.insertarArista(b,a,peso[i])))
            auxiliar=false;
        if(auxiliar)
            c++;
        else
            r++;
        auxiliar=true;
    }
    cout<<"Desde el archivo "<<ar<<" , se han cargado exitosamente "<< c <<" registros; mientras que "<<r<< " registros presentaron problemas"<<endl;
    //red.imprimirMatriz();
}


int Empresa::cargarOficinas(string of)
{
    const char *aux1= of.c_str();
    char cad[400],*aux;
    int c=0,i=0;
    ifstream arch;
    arch.open(aux1,ios::in);
    string cod, nom, dir,ciu;
    Oficina f;
    if(arch.is_open())
    {
        arch.getline(cad,400);

        while(!arch.eof())
        {
            getline(arch,cod,',');
            cod.erase(remove(cod.begin(),cod.end(),' '),cod.end());
            getline(arch,nom,',');
            nom.erase(remove(nom.begin(),nom.end(),' '),nom.end());
            getline(arch,dir,',');
            dir.erase(remove(dir.begin(),dir.end(),' '),dir.end());
            getline(arch,ciu,'\n');
            ciu.erase(remove(ciu.begin(),ciu.end(),' '),ciu.end());
            f.setNombreO("Oficina "+nom);
            f.setCodOfi(cod);
            f.setDireccionO(dir);
            f.setCiudadO(ciu);
            oficinas.push_back(f);
            c++;
        }
        cout<<"Desde el archivo "<<of<<" , se han cargado exitosamente "<< c <<" registros; mientras que "<<i<< " registros presentaron problemas"<<endl;
    }
    else
        cout<<"EL ARCHIVO NO SE ABRIO CORRECTAMENTE"<<endl;


}
void Empresa::registrarOficina()
{
    Oficina f;

    cout<<"INGRESE EL CODIGO DE LA NUEVA OFICINA"<<endl;
    string cod;
    cin>>cod;
    char nombre[100];
    f.setCodOfi(cod);
    if(red.buscarVerticeCod(f).getCodOfi()=="NO")
    {
        cout<<"INGRESE EL NOMBRE DE LA NUEVA OFICINA"<<endl;
        cin.ignore();
        cin.getline(nombre,100);
        string nombre1(nombre);
        f.setCodOfi("");
        f.setNombreO(nombre1);
        cout<<"INGRESE LA DIRECCION DE LA NUEVA OFICINA"<<endl;
        string dir;
        cin>>dir;
        cout<<"INGRESE LA CIUDAD DE LA NUEVA OFICINA"<<endl;
        string ciu;
        cin>>ciu;

        f.setCodOfi(cod);
        f.setNombreO(nombre);
        f.setDireccionO(dir);
        f.setCiudadO(ciu);
        string cp;
        Oficina p;
        red.insertarVertice(f);
        cout<<"INSERTADO CON EXITO"<<endl;
    }
    else
        cout<<"LA OFICINA IDENTIFICADA CON: "<<cod<<" YA EXISTE"<<endl;
    cin.ignore();
    return;
}
void Empresa::registrarRegion()
{
    cout<<"INGRESE EL CODIGO DE LA NUEVA REGION: "<<endl;
    string codigo;
    cin>>codigo;
    cout<<"INGRESE EL NOMBRE DE LA NUEVA REGION: "<<endl;

    char nombre1[100];
    cin.ignore();
    cin.getline(nombre1,100);
    string nombre(nombre1);
    cout<<"INGRESE EL CODIGO DE LA OFICINA DE LA NUEVA REGION: "<<endl;
    string ofi;
    cin>>ofi;
    cout<<"INGRESE EL CIUDAD DE LA NUEVA REGION: "<<endl;
    string ciu;
    cin>>ciu;

    Oficina of;
    of.setCodOfi(ofi);
    of=red.buscarVerticeCod(of);
    if(of.getCodOfi()!="NO")
    {
        Region r;
        r.setNombrer(nombre);
        r.setCodigo(codigo);
        vector<Region> re=of.getRegiones();
        for(int i=0; i<re.size(); i++)
        {
            if(re[i]==r)
            {
                cout<<"LA REGION: "<<codigo<<" YA EXISTE"<<endl;
                return;
            }
        }
        of.agregarRegion(r);
        vector<Oficina> verti= red.getVertices();
        int ind=red.indiceVertice(of);
        verti[ind]=of;
        red.setVertices(verti);
        Oficina au;
        au.setCodOfi(codigo);
        au=red.buscarVerticeCod(au);
        cout<<"INGRESE LA DISTANCIA DE LA NUEVA REGION: "<<endl;
        float dis;
        cin>>dis;
        if(au.getCodOfi()!="NO")
        {
            red.insertarArista(au,of,dis);
            red.insertarArista(of,au,dis);

        }
        else
        {
            au.setCodOfi(codigo);
            au.setCiudadO(ciu);
            au.setNombreO("Oficina" + nombre);
            if(red.insertarVertice(au))
            {
            bool a=red.insertarArista(au,of,dis);
            bool b=red.insertarArista(of,au,dis);
            if(!(a&b))
                cout<<"Error en conexion"<<endl;
            }

        }


    }
    else
    {

        cout<<"OFICINA INEXISTENTE"<<endl;
    }

    cout<<"REGION "<<codigo<<" REGISTRADA CON EXITO"<<endl;
    cin.ignore(1);
}

void Empresa::repartirPaquetes(string cod)
{

    Oficina aux;
    aux.setCodOfi(cod);
    aux=red.buscarVerticeCod(aux);
    if(aux.getNombreO()!="NO")
    {
        vector<Region> regiones= aux.getRegiones();
        if(regiones.size()==0)
            cout<<"La oficina "<<cod<<" no tiene regiones de reparto asociadas"<<endl;
        else
        {
            repartirPaquetes1(aux);

        }
    }
    else
        cout<<"La oficina no existe"<<endl;

}



void Empresa::repartirPaquetes1(Oficina ne)
{
    int n=0,l,x=0,t=0,c=0,ind2,ind1;
    bool impar;
    vector<Region> regiones=ne.getRegiones();
    x=regiones.size();
    t=x;
    vector<Oficina> verti=red.getVertices();
    for(int i=0; i<x; i++)
    {
        Oficina aux2;
        aux2.setCodOfi(regiones[i].getCodigo());
        aux2=red.buscarVerticeCod(aux2);
        if(aux2.getCodOfi()!="NO")
        {
            vector<Region> regiones2=aux2.getRegiones();
            vector<Paquete> paquetes=regiones[i].getConjunto();
            l=paquetes.size();
            int tam=regiones2.size();
            t+=tam;
            int fact;

            if(tam!=0)
            {
                fact=(l/tam);
                if(l%tam==0)
                    impar=false;
                else
                    impar=true;
            }

            else
            {
                Region r;
                r.setCodigo(aux2.getCodOfi());
                r.setNombrer(aux2.getNombreO()+" REGION UNICA");
                vector<Paquete> paqu;
                r.setConjunto(paqu);
                regiones2.push_back(r);
                fact=l;
                impar=false;
                tam=1;
            }


            vector<Paquete>::iterator it=paquetes.begin();
            for(int j=0; j <tam; j++)
            {
                vector<Paquete> paquetes2=regiones2[j].getConjunto();
                if(j==tam-(l%tam)-1 &&  impar)
                {
                    fact++;
                }
                for(int k=0; k<fact &&(paquetes.size()!=0); k++)
                {
                    if(k==0)
                        c++;
                    paquetes2.push_back(*it);
                    paquetes.erase(it);
                    it=paquetes.begin();
                    n++;
                }
                regiones2[j].setConjunto(paquetes2);
            }
            regiones[i].setConjunto(paquetes);
            aux2.setRegiones(regiones2);
            ind2=red.indiceVertice(aux2);
            verti[ind2]=aux2;
        }
        else
            cout<<"FAIL"<<endl;
        ne.setRegiones(regiones);
    }
    ind1=red.indiceVertice(ne);
    verti[ind1]=ne;
    red.setVertices(verti);
    cout<<endl<<"Se han repartido exitosamente "<<n<<" paquetes en "<<c<<" oficinas de las "<<t<<" oficinas asociadas con regiones de reparto de la oficina "<< "."<<endl;
}

bool Empresa::sinOficinas()
{
    if(red.esVacio())
        return true;
    else
        return false;
}
string Empresa::trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


vector<Oficina> Empresa::getOficinas()
{
    return oficinas;
}
void Empresa::setOficinas (vector<Oficina> ofi)
{
    oficinas=ofi;
}

Oficina* Empresa::buscarVecOfi(string cod)
{
    Oficina* of=NULL;
    for(int i=0; i<oficinas.size(); i++)
    {
        if(oficinas[i].getCodOfi()==cod)
        {
            of=&oficinas[i];
        }
    }
    return of;
}

void Empresa::cargarConexiones(string nom)
{
    const char* nb=nom.c_str();
    ifstream arch;
    arch.open(nb,ios::in);
    string o,d,pes;
    char holi[400];
    int peso,c=0,i=0;
    if(arch.is_open())
    {
        arch.getline(holi,400);

        while(!arch.eof())
        {
            getline(arch,o,',');
            o.erase(remove(o.begin(),o.end(),' '),o.end());
            getline(arch,d,',');
            d.erase(remove(d.begin(),d.end(),' '),d.end());
            getline(arch,pes,'\n');
            pes.erase(remove(pes.begin(),pes.end(),' '),pes.end());
            peso=stoi(pes);
            Oficina a;
            a.setCodOfi(o);
            Oficina ori=red.buscarVerticeCod(a);
            a.setCodOfi(d);
            Oficina des=red.buscarVerticeCod(a);
            if(red.insertarArista(ori,des,peso) &&red.insertarArista(des,ori,peso))
                c++;
            else
                i++;
        }

        cout<<"Desde el archivo "<<nom<<" , se han cargado exitosamente "<< c <<" registros; mientras que "<<i<< " registros presentaron problemas"<<endl;
    }
    else
    {
        cout<<"El archivo "<<nom<< " no existe"<<endl;
    }

}

void Empresa::rutaReparto(string origen, string destino)
{
    Oficina ori;
    Oficina des;
    ori.setCodOfi(origen);
    des.setCodOfi(destino);
    ori=red.buscarVerticeCod(ori);
    des=red.buscarVerticeCod(des);
    int indOrigen=red.indiceVertice(ori);
    int indDestino=red.indiceVertice(des);
    vector<Oficina> vertices=red.getVertices();
    vector<vector<float> > dik=red.Dikjstra(ori);
    vector<float> dis=dik[0];
    vector<float> pre=dik[1];

    if(dis[indDestino]==INF)
    {
        cout<<"Lo sentimos, Actualmente no hay rutas disponibles desde "<< origen<<" hasta "<<destino<<endl;
    }else if(ori==des)
    {
        cout<<"Son la misma oficina"<<endl;
    }
    else
    {
        cout<<"La ruta mas corta tiene "<< dis[indDestino]<<" km, y es: "<<endl;
        vector<Oficina> ruta;

        Oficina a=vertices[indDestino];
        ruta.push_back(vertices[indDestino]);
        int aux=pre[indDestino];

        while(a.getCodOfi()!=ori.getCodOfi())
        {
            a=vertices[aux];
            ruta.push_back(a);
            aux=pre[aux];
        }
        reverse(ruta.begin(),ruta.end());
        Oficina act=ruta[0];
        Oficina sig=ruta[1];
        cout<<act.getCodOfi()<<endl;
        int con=1;
        while(con<ruta.size())
        {
            int indAct=red.indiceVertice(act);
            int indSig=red.indiceVertice(sig);
            float dis=red.getPeso(indAct,indSig);
            cout<< dis<< "Km."<<endl;
            cout<<sig.getCodOfi()<<endl;
            act=sig;
            if(con+1<ruta.size())
            {
                sig=ruta[con+1];
            }
            con++;
        }
    }
}



#endif // TADEMPRESA_HXX_INCLUDED
