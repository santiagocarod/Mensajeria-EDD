#include <iostream>
#include <string.h>
#include "TADPersonas.h"
#include "TADPaquete.h"
#include "TADRegion.h"
#include "TADOficina.h"
#include "TADEmpresa.h"
#include "TADNodo.h"
#include <vector>
using namespace std;

int main()
{
	Empresa e;
	bool salida=false;
	char entrada[100];
	char * aux;
	int con=0;
	vector<string> cas;
	do
	{
		cas.clear();
		cout<<"$";
		cin.getline(entrada,100);
		con++;
		aux=strtok(entrada, " ");
		while(aux!= NULL)
		{
			string s(aux);
			cas.push_back(s);
			aux=strtok(NULL, " ");
		}
		if(cas[0]=="rutaReparto")
		{
			if(cas.size()!=3)
				cout<<"Sintaxis del comando erronea"<<endl;
			else
				e.rutaReparto(cas[1],cas[2]);
		}
		else if(cas[0]=="cargarPersonas")
		{
			if(cas.size()!=2)
				cout<<"Sintaxis del comando erronea"<<endl;
			else
				e.cargarPersonas(cas[1]);
		}
		else
		{

			if(cas[0]=="cargarPaquetes")
			{
				if(cas.size()!=2)
					cout<<"Sintaxis del comando erronea"<<endl;
				else
					e.leerArchivoPaquetes(cas[1]);

			}
			else
			{
				if(cas[0]=="registrarPersona")
				{
					if(cas.size()!=1)
						cout<<"Sintaxis del comando erronea"<<endl;
					else
						e.registrarPersona();
				}
				else
				{
					if(cas[0]=="registrarPaquete")
					{
						if(cas.size()!=1)
							cout<<"Sintaxis del comando erronea"<<endl;
						else
							e.ingresarPaquete();
					}
					else
					{

						if(cas[0]=="conteoPaquetes")
						{
							if(cas.size()!=1)
								cout<<"Sintaxis del comando erronea"<<endl;
							else if(!e.sinPaquetes())
								e.conteoPaquetes();
							else
								cout<<" No existe informacion de paquetes registrada en el sistema."<<endl;
						}
						else

						{
							if(cas[0]=="cargarOficinas")
							{
								if(cas.size()!=2)
									cout<<"Sintaxis del comando erronea"<<endl;
								else
									e.cargarOficinas(cas[1]);

							}
							else if(cas[0]=="cargarRegiones")
							{
								if(cas.size()!=2)
									cout<<"Sintaxis del comando erronea"<<endl;
								else
									e.cargarRegiones(cas[1]);

							}
							else if(cas[0]=="cargarConexiones")
							{
								if(cas.size()!=2)
									cout<<"Sintaxis del comando erronea"<<endl;
								else
									e.cargarConexiones(cas[1]);

							}
							else if(cas[0]=="registrarOficina")
							{
								e.registrarOficina();
							}
							else if(cas[0]=="registrarRegion")
							{
								e.registrarRegion();
							}
							else if(cas[0]=="repartirPaquetes")
							{
								if(cas.size()!=2)
									cout<<"Sintaxis del comando erronea"<<endl;
								else
									e.repartirPaquetes(cas[1]);
							}
							else
							{
								if(cas[0]=="salir")
									salida=true;
								else
								{
									if(cas[0]=="ayuda")
									{
										if(cas.size()==1)
										{
											cout<<"COMANDOS DISPONIBLES:"<<endl<<"cargarPersonas"<<endl<<"cargarPaquetes"<<endl<<"cargarOficinas"<<endl<<"cargarRegiones"<<endl<<"cargarConexiones"<<endl<<"registrarPersona"<<endl<<"registrarPaquete"<<endl<<"registrarRegion"<<endl<<"registrarOficina"<<endl<<"conteoPaquetes"<<endl<<"repartirPaquetes"<<endl<<"rutaReparto"<<endl<<"ayuda 'comando'"<<endl<<"salir"<<endl;
										}
										else
										{
											if(cas.size()==2)
											{
												if(cas[1]=="cargarPersonas")
												{
													cout<<"cargarPersonas 'nombreArchivo': Carga en memoria la informacion contenida en el archivo identificado por nombre_archivo, la cual debe corresponder a la informacion basica de un grupo de personas"<<endl;
												}
												else
												{

													if(cas[1]=="cargarPaquetes")
													{
														cout<<"cargarPaquetes 'nombreArchivo': Carga en memoria la informacion contenida en el archivo identificado por nombre_archivo,la cual debe corresponder a la informacion basica de un grupo de paquetes."<<endl;
													}
													else if(cas[1]=="cargarOficinas")
													{
														cout<<"cargarOficinas 'nombreArchivo': Carga en memoria la informacion contenida en el archivo identificado por nombre_archivo,la cual debe corresponder a la informacion basica de un conjunto de oficinas."<<endl;
													}
													else if(cas[1]=="cargarRegiones")
													{
														cout<<"cargarRegiones 'nombreArchivo': Carga en memoria la informacion contenida en el archivo identificado por nombre_archivo,la cual debe corresponder a la informacion basica de un conjunto de regiones."<<endl;

													}
													else if(cas[1]=="cargarConexiones")
													{
														cout<<"cargarConexiones 'nombreArchivo': Carga en memoria la información contenida en el archivo identificado por nombre_archivo,la cual debe corresponder a la información básica de las conexiones entre oficinas "<<endl;

													}
													else
													{
														if(cas[1]=="registrarPersona")
														{

															cout<<"registrarPersona:Permite insertar en el sistema la informacion asociada de una persona, para usarla posteriormente como remitente o destinatario de un paquete a enviar"<<endl;
														}
														else
														{
															if(cas[1]=="registrarPaquete")
															{
																cout<<"registrarPaquete:Permite insertar en el sistema un paquete a entregar con toda su informacion asociada."<<endl;
															}
															else if(cas[1]=="registrarRegion")
															{
																cout<<"registrarRegion: Permite insertar en el sistema la informacion asociada de una region, e interconectarla con la oficina respectiva."<<endl;
															}
															else if(cas[1]=="rutaReparto")
															{
																cout<<"rutaReparto: Reporta los códigos de las oficinas que conforman la ruta más corta entre las oficinas dadas,generando así la ruta de reparto. Informa, además, la distancia total de la ruta calculada."<<endl;
															}
															else if(cas[1]=="registrarOficina")
															{
																cout<<"registrarOficina:Permite insertar en el sistema la informacion asociada de una oficina."<<endl;
															}
															else
															{

																if(cas[1]=="conteoPaquetes")
																{
																	cout<<"conteoPaquetes: De acuerdo a la informacion almacenada, realiza el conteo de los paquetes registrados que se encuentran pendientes por entregar. "<<endl;
																}
																else if(cas[1]=="repartirPaquetes")
																{
																	cout<<"repartirPaquetes 'codigo_oficina':el comando distribuye los paquetes almacenados en las regiones de reparto de la oficina dada y los ubica en las oficinas respectivas, distribuyendolos de forma equitativa en las regiones de reparto de las oficinas dependientes."<<endl;
																}
																else
																{
																	if(cas[1]=="salir")
																		cout<<"salir: Finaliza la ejecucion de la aplicacion."<<endl;
																	else
																		cout<<"Comando inexistente."<<endl;
																}

															}
														}

													}

												}
											}
											else
												cout<<"Sintaxis del comando erronea"<<endl;

										}
									}
									else
										cout<<"Comando inexistente"<<endl;

								}
							}

						}
					}
				}
			}
		}
	}
	while(!salida);
}
