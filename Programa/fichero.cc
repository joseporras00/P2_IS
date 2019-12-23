#include "fichero.h"

void escribeClientes(list <Usuario> lista) {
	ofstream f1("clientes.txt");

	list <Usuario> :: iterator i;

	for(i=lista.begin() ; i!=lista.end() ; ++i) {
		f1 << (*i).dni_ << "," << (*i).nombre_;		
		f1 << "," << (*i).apellidos_ << "," << (*i).telefono_;
		f1 << "," << ((*i).cita_).fecha_ << "," << ((*i).cita_).hora_;
		f1 << "," << ((*i).tratamiento_).nombre_ << "," <<((*i).tratamiento_).cantidad_<<endl;
	
	}

	f1.close();
}

void leeClientes(list <Usuario> *lista) {
	ifstream f1("clientes.txt");

	(*lista).clear();

	Cita cita;
	Tratamiento tratamiento;

	char dni[10], nombre[30], apellidos[30];
	char telefono[9], fecha[15], hora[10];
	char trat1[50], trat2[50];

	Usuario aux(nombre,apellidos,telefono,dni,cita,tratamiento);

	if(f1.is_open()) {
		while(f1.getline(dni, 10, ',')) {
			f1.getline(nombre, 30, ',');
			f1.getline(apellidos, 30, ',');
			f1.getline(telefono, 9, ',');
			f1.getline(fecha, 15, ',');
			f1.getline(hora, 10, ',');
			f1.getline(trat1, 50, ',');
			f1.getline(trat2, 50, '\n');
			aux.dni_=dni;				
			aux.nombre_=nombre;
			aux.apellidos_=apellidos;
			aux.telefono_=telefono;
			(aux.cita_).fecha_=fecha;
			(aux.cita_).hora_=hora;
			(aux.tratamiento_).nombre_=trat1;
			(aux.tratamiento_).cantidad_=trat2;
			(*lista).push_back(aux);	
		}
		f1.close();	
	} else cout << "\nNo se pudo abrir el fichero, puede que no exista\n" << endl;
}

void leeHistorial(list <Usuario> *lista)
{
	ifstream f2("historiales.txt");
	
	list <Usuario> :: iterator i;
	
	char nif[10], historial[2000];
	
	if(f2.is_open()) 
	{
		while(f2.getline(nif, 10, ',')) 
		{
			f2.getline(historial, 2000, '\t');
			for(i=(*lista).begin();i!=(*lista).end();++i)
			{
				if(nif==(*i).dni_)
				{
					(*i).historial_=historial;
				}
			}
		}
		f2.close();	
	} else cout << "\nNo se pudo abrir el fichero, puede que no exista\n" << endl;
	
	
	
	
}

void escribeHistorial(list <Usuario> lista)
{
	ofstream f2("historiales.txt");
	
	list <Usuario> :: iterator i;

	for(i=lista.begin() ; i!=lista.end() ; ++i) 
	{
	
		f2 << (*i).dni_ << "," << (*i).historial_ << "\t";
		
	}
	f2.close();
}





























