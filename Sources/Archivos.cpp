#include "../Headers/Archivos.h"

char* capturarArchivo(char* nombre){
    fstream archivo;
    int longitud;
    archivo.open(nombre, ios_base::in | ios_base::binary);
    archivo.seekp(0, archivo.end);
    longitud = archivo.tellp();
    char* contenido = new char[longitud];
    archivo.seekp(0);
    for(int contador = 0; contador < longitud; contador++){
        contenido[contador] = archivo.get();
    }
    contenido[longitud] = '\0';
    archivo.close();
    return contenido;
}
void escribirArchivo(unsigned long long longitud, char* nombre, string contenido){
    fstream archivo;
    archivo.open(nombre, ios_base::out);
    archivo.write(contenido.c_str(), longitud);
    archivo.close();
}
