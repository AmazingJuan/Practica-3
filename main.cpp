#include <iostream>
#include <Archivos.h>
#include <Utilidades.h>
#include <Decodificacion.h>
#include <Codificacion.h>

using namespace std;

int main()
{
    string cadena = capturarArchivo("hola.txt");
    string binario = stringToBin(cadena);
    string codificado = codSegundoMetodo(2, binario);
    string decodificado = decSegundoMetodo(2, codificado);
    string cadenita = binToString(decodificado);
    escribirArchivo((unsigned long long) cadenita.size(),"hola.dat", cadenita);

    cout << binario;

}
