#ifndef UTILIDADES_H
#define UTILIDADES_H

#endif // UTILIDADES_H
#include "Importaciones.h"
short elevar(short numero, short potencia);
string charToBin(char);
string stringToBin(string cadena);
char binToChar(string binario);
string binToString(string binario);
int invertirBit(char bit);
void contarBin(string binario, int contadores[2]);
bool stringInArray(string cadena, string* arreglo, int lenArreglo);
void stringToChar(string cadena, char *caracter);
string* crearArray(string entrada, int lenArray);
void limpiarPantalla();
void congelarPantalla();
string obtenerMensaje(string parametro);
int contarSeparador(string cadena, string separador);
void congelarPantalla(int segundos);

