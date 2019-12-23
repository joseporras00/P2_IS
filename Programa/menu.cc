#include "funciones.h"
using namespace std;

int main()
{
	list <Usuario> lista;
	int opcion=0;
	string nombre, apellidos, telefono, dni, fecha;
	Cita cita;
	Tratamiento tratamiento;
	Usuario aux(nombre,apellidos,telefono,dni,cita,tratamiento);
	bool correcto;

	
	do
	{	
		leeClientes(&lista);	
		cout<<"___________________________________________________________________\n\n1. Mostrar agenda\n2. Mostrar listado\n3. Anadir usuario\n4. Borrar usuario\n5. Salir\n\n\tElige una opcion: ";
		cin>>opcion;

		switch(opcion)
		{
			case 1:
				system("clear");
				
				if(lista.empty())
					cout<<"\nLa lista de usuarios esta vacia\n";
				else
				{
					cin.ignore();
					cout<<"Introduce la fecha que quieres comprobar(DD/MM/AAAA): ";
					getline(cin, fecha);
					cout<<endl;
					mostrarAgenda(lista, fecha);
				}

				break;

			case 2:
				system("clear");
				mostrarLista(lista);
				
				if(lista.empty())
					cout<<"\nLa lista de usuarios esta vacia\n";
				else
				{
					cin.ignore();
					cout<<"\nIntroduce el dni del usuario buscado: ";
					getline(cin, dni);
				
					buscarUsuario(&lista, dni);
					escribeClientes(lista);
				}
				
				break;

			case 3:
				correcto=true;
				system("clear");
				cin.ignore();
				cout<<"\nNuevo usuario\n______________\n\nIntroduce el nombre del nuevo usuario: ";
				getline(cin, aux.nombre_);
				cout<<"Introduce los apellidos: ";
				getline(cin, aux.apellidos_);
				cout<<"Introduce el telefono: ";
				getline(cin, aux.telefono_);
				cout<<"Introduce el dni: ";
				getline(cin, aux.dni_);

				if(((aux.telefono_).size()!=9)||((aux.dni_).size()!=9))
				{
					correcto=false;
					if((aux.telefono_).size()!=9)
						cout<<"\nFormato del telefono introducido incorrecto, vuelva a intentarlo\n";
					if((aux.dni_).size()!=9)
						cout<<"\nFormato del dni introducido incorrecto, vuelva a intentarlo\n";
				}

				if(correcto==true)
				{
					anadirUsuario(aux, &lista);
					escribeClientes(lista);
				}
				break;
			
			case 4:
				system("clear");
				mostrarLista(lista);
				
				if(lista.empty())
					cout<<"\nLa lista de usuarios esta vacia\n";
				else
				{
					cin.ignore();
					cout<<"\nIntroduce el dni del usuario que quieres borrar: ";
					getline(cin, dni);
				
					borrarUsuario(&lista, dni);
					escribeClientes(lista);				
				}				
				break;

			case 5:
				system("clear");
				cout<<"\nFin del programa\n\n";
				break;
				
			default:
				cout<<"\nOpcion incorrecta, elija un numero entre 1 y 4\n";
				break;
		}
	}while(opcion!=5);

	return 0;
}
