#ifndef VALIDACION_H
#define VALIDACION_H

#include "Importaciones.h"
bool validarOpcion(string entrada, string *opciones, int lenOpciones);
bool validarEntrada(string entrada, bool isNumero, int longitudMin, int longMax, bool isSaldo);

#endif // VALIDACION_H
