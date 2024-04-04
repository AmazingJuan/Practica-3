#ifndef MENUS_H
#define MENUS_H
#include "Importaciones.h"

int menuOpcion(string mensaje, string *opciones, int lenOpcion);
string menuEntrada(string mensaje, bool isNumero, int longMin, int longMax, bool isSaldo);

#endif // MENUS_H
