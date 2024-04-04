#include "../Headers/Archivos.h"
#include <vector>
#include "locale"

string capturarArchivo(char* nombre){
    ifstream archivo;
    string cadena;
    archivo.open(nombre, ifstream::binary | ios_base::in);
    archivo.seekg (0, archivo.end);
    int longitud = archivo.tellg();
    archivo.seekg (0, archivo.beg);
    for(int cont = 0; cont < longitud; cont++) cadena += archivo.get();
    return cadena;
}
void escribirArchivo(unsigned long long longitud, char* nombre, string contenido){
    fstream archivo;
    archivo.open(nombre, ios_base::out | ios_base::binary);
    archivo.write(contenido.c_str(), longitud);
    archivo.close();
}
