#ifndef FICHERO_H
#define FICHERO_H

#include <fstream>
#include <list>
#include "usuario.h"
using namespace std;

void escribeClientes(list <Usuario> lista);
void leeClientes(list <Usuario> *lista);
void leeHistorial(list <Usuario> *lista);
void escribeHistorial(list <Usuario> lista);

#endif
