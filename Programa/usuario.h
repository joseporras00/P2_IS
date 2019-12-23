#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include "clases.h"
using namespace std;

class Usuario
 {
 	public:
 		string nombre_, apellidos_, dni_, telefono_ ;
 		Cita cita_;
 		Tratamiento tratamiento_;
 		string historial_;

 		Usuario(string nombre, string apellidos, string telefono, string dni, 
 		Cita cita, Tratamiento tratamiento);
 };

#endif
