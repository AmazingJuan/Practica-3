#ifndef BANCO_H
#define BANCO_H

#include "Importaciones.h"
#include "Codificacion.h"
#include "Decodificacion.h"
#include "Archivos.h"

int ***obtenerDatos(char *cuentasNormal);
int *existeUsuario(int **cuentasNormal, int **cuentasAdmin, int documento, int *longitudArreglos);
void guardarDatos(int **cuentasUsu, int lenCuentas, char *archivo);
int*** anadirCuenta(int ***datos,  int documento, int clave, int saldo);

#endif // BANCO_H
