#include "usuario.h"

Usuario::Usuario(string nombre, string apellidos, string telefono, string dni, Cita cita, Tratamiento tratamiento)
{
	nombre_=nombre;
	apellidos_=apellidos;
	telefono_=telefono;
	dni_=dni;
	cita_=cita;
	tratamiento_=tratamiento;
}
