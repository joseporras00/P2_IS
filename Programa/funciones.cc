#include "funciones.h"

void anadirUsuario(Usuario aux, list <Usuario> *lista)
{
	list <Usuario> :: iterator i;
	int o=0;
	
	for(i=(*lista).begin();i!=(*lista).end();++i)
	{
		if((*i).dni_==aux.dni_)
		{
			cout<<"\nEl dni del usuario coincide con uno ya registrado\n";
			o=1;
		}
	}
	
	if(o==0)
	{
		(*lista).push_back(aux);
		cout<<"\nUsuario registrado con exito\n";
	}
}

void mostrarLista(list <Usuario> lista)
{
	list <Usuario> :: iterator i;

	for(i=lista.begin();i!=lista.end();++i)
	{
		cout<<endl<<(*i).dni_<<"\t"<<(*i).nombre_<<" "<<(*i).apellidos_<<"\n";
	}
}

void buscarUsuario(list <Usuario> *lista, string dni)
{
	list <Usuario> :: iterator i,o;
	int opcion, e=0, f=0, g=0;
	string ultimo;
	
	for(i=(*lista).begin();i!=(*lista).end();++i)
	{
		if(dni==(*i).dni_)
		{
			e=1;
			system("clear");
			do
			{				
				escribeClientes(*lista);
				leeHistorial(lista);
				cout<<"___________________________________________________________________\n\nNombre: "<<(*i).nombre_<<"\nApellidos: "<<(*i).apellidos_<<"\nTelefono: "<<(*i).telefono_<<"\nDni: "<<(*i).dni_;
						
				if((((*i).cita_).fecha_).empty())
					cout<<"\nCita: No hay cita";
				else
					cout<<"\nCita: "<<((*i).cita_).fecha_<<" "<<((*i).cita_).hora_;
							
				if((((*i).tratamiento_).nombre_).empty())
					cout<<"\nTratamiento: No hay tratamiento\n";
				else
					cout<<"\nTratamiento: "<<((*i).tratamiento_).nombre_<<" "<<((*i).tratamiento_).cantidad_<<endl;
				
				cout<<"___________________________________________________________________\n\n1. Crear cita\n2. Editar cita\n3. Borrar cita\n4. Crear tratamiento\n5. Editar tratamiento\n6. Borrar tratamiento\n7. Ver historial\n8. Salir del usuario\n\n\tElige una opcion: ";
				cin>>opcion;
				
				switch(opcion)
				{
					case 1:
						system("clear");
						f=0;
						
						if((((*i).cita_).fecha_).empty())
						{
							do
							{							
								cin.ignore();
								cout<<"\nNueva cita\n___________\n\nIntroduce la fecha de la cita (DD/MM/AAAA): ";
								getline(cin,((*i).cita_).fecha_);
								cout<<"\nIntroduce la hora de la cita (HH:MM): ";
								getline(cin,((*i).cita_).hora_);						
								
								g=0;
								for(o=(*lista).begin();o!=(*lista).end();++o)
								{
									if(((*o).dni_)!=((*i).dni_))
									{
										if((((*o).cita_).fecha_)==(((*i).cita_).fecha_))
										{
											if((((*o).cita_).hora_)==(((*i).cita_).hora_))
											{
												cout<<"\nNo se puede concretar la cita porque ya existe una a la misma hora\n";												
												g=1;										
											}
										}
									}									
								}								
								
								if(g==0)
								{
									if(((((*i).cita_).fecha_).size()==10)&&((((*i).cita_).hora_).size()==5))
									{
										cout<<"\nCita introducida con exito\n";
										ultimo="Cita creada: "+((*i).cita_).fecha_+" "+((*i).cita_).hora_+"\n";
										(*i).historial_=(*i).historial_ + ultimo;
										escribeHistorial(*lista);
										f=1;
									}
									else if((((*i).cita_).fecha_).size()!=10)
										cout<<"\nFormato de la fecha introducida incorrecto, vuelva a intentarlo\n";
									else if((((*i).cita_).hora_).size()!=5)
										cout<<"\nFormato de la hora introducida incorrecto, vuelva a intentarlo\n";
								}									
							}while(f!=1);
						}
						else
							cout<<"\nYa existe una cita para este usuario, en caso de querer editarla elija la opcion 2\n";
					
					break;

					case 2:
						system("clear");
						
						if((((*i).cita_).fecha_).empty())
							cout<<"\nNo existe ninguna cita, para crearla elija la opcion 1\n";
						else
						{
							do
							{
								cout<<"\nLa cita actual: "<<((*i).cita_).fecha_<<" "<<((*i).cita_).hora_<<endl;
								cin.ignore();
								cout<<"\nIntroduce la fecha de la cita nueva (DD/MM/AAAA): ";
								getline(cin,((*i).cita_).fecha_);
								cout<<"\nIntroduce la hora de la cita nueva (HH:MM): ";
								getline(cin,((*i).cita_).hora_);								
								
								g=0;
								for(o=(*lista).begin();o!=(*lista).end();++o)
								{
									if(((*o).cita_).fecha_==((*i).cita_).fecha_)
									{
										if(((*o).cita_).hora_==((*i).cita_).hora_)
										{
											cout<<"\nNo se puede concretar la cita porque ya existe una a la misma hora\n";
											g=1;										
										}
									}
								}	
								if(g==0)
								{
									if(((((*i).cita_).fecha_).size()==10)&&((((*i).cita_).hora_).size()==5))
									{
										cout<<"\nCita introducida con exito\n";
										ultimo="Cita editada: "+((*i).cita_).fecha_+" "+((*i).cita_).hora_+"\n";
										(*i).historial_=(*i).historial_ + ultimo;
										escribeHistorial(*lista);
										f=1;
									}
									else if((((*i).cita_).fecha_).size()!=10)
										cout<<"\nFormato de la fecha introducida incorrecto, vuelva a intentarlo\n";
									else if((((*i).cita_).hora_).size()==5)
										cout<<"\nFormato de la hora introducida incorrecto, vuelva a intentarlo\n";
								}
								
							}while(f!=1);
						}
					
					break;
					
					case 3:
						system("clear");
						
						if((((*i).cita_).fecha_).empty())
							cout<<"\nNo existe ninguna cita, para crearla elija la opcion 1\n";
						else
						{
							(((*i).cita_).fecha_).clear();
							(((*i).cita_).hora_).clear();
							
							cout<<"\nCita borrada con exito\n";
							
							ultimo="Cita borrada\n";
							(*i).historial_=(*i).historial_ + ultimo;
							escribeHistorial(*lista);
						}
						
					break;

					case 4:
						system("clear");
						f=0;
						
						if((((*i).tratamiento_).nombre_).empty())
						{
							do
							{
								cin.ignore();
								cout<<"\nNuevo tratamiento\n______________\n\nIntroduce el nombre del tratamiento: ";
								getline(cin,((*i).tratamiento_).nombre_);
								cout<<"\nIntroduce la cantidad de tratamiento: ";
								getline(cin,((*i).tratamiento_).cantidad_);
								
								if(((((*i).tratamiento_).nombre_).empty())||((((*i).tratamiento_).cantidad_).empty()))
									cout<<"\nDatos introducidos incorrectos, vuelva a intentarlo\n";
								else
								{
									cout<<"\nTratamiento introducido con exito\n";
									f=1;
									ultimo="Tratamiento creado: "+((*i).tratamiento_).nombre_+" "+((*i).tratamiento_).cantidad_+"\n";
									(*i).historial_=(*i).historial_ + ultimo;
									escribeHistorial(*lista);
								}
							}while(f!=1);
						}
						else
							cout<<"\nYa existe un tratamiento para este usuario, en caso de querer editarlo elija la opcion 5\n";
					
				
					break;
					
					case 5:
						system("clear");
						
						if((((*i).tratamiento_).nombre_).empty())
							cout<<"\nNo existe ningun tratamiento, para crearlo elija la opcion 4\n";
						else
						{
							do
							{
								cout<<"\nEl tratamiento actual: "<<((*i).tratamiento_).nombre_<<" "<<((*i).tratamiento_).cantidad_<<endl;
								cin.ignore();
								cout<<"\nIntroduce el nombre del nuevo tratamiento: ";
								getline(cin,((*i).tratamiento_).nombre_);
								cout<<"\nIntroduce la cantidad del nuevo tratamiento: ";
								getline(cin,((*i).tratamiento_).cantidad_);
								
								if(((((*i).tratamiento_).nombre_).empty())||((((*i).tratamiento_).cantidad_).empty()))
									cout<<"\nDatos introducidos incorrectos, vuelva a intentarlo\n";
								else
								{
									cout<<"\nTratamiento introducido con exito\n";
									f=1;
									ultimo="Tratamiento editado: "+((*i).tratamiento_).nombre_+" "+((*i).tratamiento_).cantidad_+"\n";
									(*i).historial_=(*i).historial_ + ultimo;
									escribeHistorial(*lista);
								}
							}while(f!=1);
						}
					break;
					
					case 6:
						system("clear");
						
						if((((*i).tratamiento_).nombre_).empty())
							cout<<"\nNo existe ningun tratamiento, para crearlo elija la opcion 4\n";
						else
						{
							(((*i).tratamiento_).nombre_).clear();
							(((*i).tratamiento_).cantidad_).clear();
							
							cout<<"\nTratamiento borrado con exito\n";
							ultimo="Tratamiento borrado\n";
							(*i).historial_=(*i).historial_ + ultimo;
							escribeHistorial(*lista);
						}
						
					break;
					
					case 7:
						system("clear");
						if(((*i).historial_).empty())
							cout<<endl<<"No existe historial de este usuario\n";
						else
							cout<<endl<<(*i).historial_;
						
					break;
					
					case 8:
						
					break;
					
					default:
						cout<<"\nOpcion incorrecta, elija un numero entre 1 y 8\n";

					break;
				}
			}while(opcion!=8);
		}
	}
	
	if(e==0)
		cout<<"\nUsuario no encontrado\n";
	else
		system("clear");
}

void borrarUsuario(list <Usuario> *lista, string dni)
{
	list <Usuario> :: iterator i;
	int e=0;
	string conf="N";
	
	for(i=(*lista).begin();i!=(*lista).end();++i)
	{
		conf="N";
		if((*i).dni_==dni)
		{
			e=1;
			cout<<"Introduce S para confirmar: ";
			getline(cin, conf);
			if(conf=="S")
			{
				(*lista).erase(i);
				cout<<"\nUsuario eliminado con exito\n";
			}
			else
				cout<<"\nNo se confirmo correctamente\n";
			break;
		}
	}
	if(e==0)
		cout<<"\nUsuario no encontrado\n";
}

void mostrarAgenda(list <Usuario> lista, string fecha)
{
	list <Usuario> :: iterator i;
	
	for(i=lista.begin();i!=lista.end();++i)
	{
		if(fecha==(((*i).cita_).fecha_))
		{
			cout<<(*i).dni_<<"\t"<<(*i).nombre_<<" "<<(*i).apellidos_<<"\t"<<(*i).telefono_<<"\t"<<(((*i).cita_).hora_)<<endl;
		}
	}
}

