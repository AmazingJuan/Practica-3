#include "../Headers/Codificacion.h"
#include "../Headers/Utilidades.h"

string codPrimerMetodo(int semilla, string binario){
    string codificacion = "";
    int contadores[2];
    int contadorBloque = 1;

    for(int contador = 0; contador < semilla; contador++){
        if(binario[contador] % 48 == 0) codificacion += 49;
        else codificacion += 48;
    }

    for(unsigned long long contador = semilla; contador < binario.size(); contador+= semilla){
        contarBin(binario.substr(contador - semilla, semilla), contadores);
        for(int contador2 = contador; contador2 + semilla < contador + 2*semilla; contador2++){
            if(contadores[0] == contadores[1]){
                codificacion += invertirBit(binario[contador2]);
            }
            else if(contadores[0] > contadores[1] && contadorBloque % 2 == 0) codificacion += invertirBit(binario[contador2]);
            else if(contadores[0] < contadores[1] && contadorBloque % 3 == 0) codificacion += invertirBit(binario[contador2]);
            else codificacion += binario[contador2];
            contadorBloque++;
        }
        contadorBloque = 1;
    }
    return codificacion;
}

string codSegundoMetodo(int semilla, string binario){
    string codificacion = "";
    char *aux = new char[semilla];
    aux[semilla] = '\0';
    for(int contador = 0; contador < binario.size(); contador += semilla){
        for(int contador2 = 0; contador2 < semilla; contador2++){
            aux[(contador2 + 1) % semilla] = binario[contador + contador2];
        }
        codificacion += aux;
    }
    delete [] aux;

    return codificacion;
}
