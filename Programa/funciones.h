#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "fichero.h"
#include <cstdlib>
using namespace std;

void anadirUsuario(Usuario aux, list <Usuario> *lista);
void mostrarLista(list <Usuario> lista);
void buscarUsuario(list <Usuario> *lista, string dni);
void borrarUsuario(list <Usuario> *lista, string dni);
void mostrarAgenda(list <Usuario> lista, string fecha);

#endif
