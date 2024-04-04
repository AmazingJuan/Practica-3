#include "../Headers/Decodificacion.h"

string decPrimerMetodo(int semilla, string binario){
    string decodificacion = "";
    int contadores[2];
    int contadorBloque = 1;

    for(int contador = 0; contador < semilla; contador++){
        if(binario[contador] % 48 == 0) decodificacion += 49;
        else decodificacion += 48;
    }

    for(unsigned long long contador = 0; contador + semilla < binario.size(); contador+= semilla){
        contarBin(decodificacion.substr(contador, semilla), contadores);
        for(int contador2 = contador + semilla; contador2 < contador + 2*semilla; contador2++){
            if(contadores[0] == contadores[1]){
                decodificacion += invertirBit(binario[contador2]);
            }
            else if(contadores[0] > contadores[1] && contadorBloque % 2 == 0) decodificacion += invertirBit(binario[contador2]);
            else if(contadores[0] < contadores[1] && contadorBloque % 3 == 0) decodificacion += invertirBit(binario[contador2]);
            else decodificacion += binario[contador2];
            contadorBloque++;
        }
        contadorBloque = 1;
    }
    return decodificacion;
}

string decSegundoMetodo(int semilla, string binario){
    string codificacion = "";
    char *aux = new char[semilla + 1];
    aux[semilla] = '\0';
    for(unsigned long long contador = 0; contador < binario.size(); contador += semilla){
        for(int contador2 = 0; contador2 < semilla; contador2++){
            if(contador2 - 1 == -1){
                aux[semilla - 1] = binario[contador + contador2];
            }
            else{
                aux[contador2 - 1] = binario[contador + contador2];
            }
        }
        codificacion += aux;
    }
    delete [] aux;

    return codificacion;
}
