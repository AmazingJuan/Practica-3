#include <Utilidades.h>
#include <iostream>

short elevar(short numero, short potencia){
    short resultado = 1;
    for(short contador = 0; contador < potencia; contador++) resultado *= numero;
    return resultado;
}

string charToBin(char caracter){
    int decimal = caracter;
    int aux = 8;
    char cadena[9];
    string retorno;
    cadena[8] = '\0';
    while(aux != 0){
        cadena[aux - 1] = decimal % 2 + 48;
        decimal /= 2;
        aux--;
    }
    retorno = cadena;
    return retorno;
}

string stringToBin(string cadena){
    string binario = "";
    for(unsigned long long contador = 0; contador < cadena.size(); contador++) binario.append(charToBin(cadena[contador]));
    return binario;
}

string binToString(string binario){
    string cadena = "";
    string cadenaAux = "";
    for(int contador = 0; contador < binario.size(); contador += 8){
        for(int contador2 = 0; contador2 < 8; contador2++) cadenaAux += binario[contador + contador2];
        cadena += binToChar(cadenaAux);
        cadenaAux = "";
    }
    return cadena;

}

char binToChar(string binario){
    char caracter = 0;
    for(short contador = 0; contador <= 7; contador++){
        if(binario[contador] == 49){
            caracter += elevar(2, 7 - contador);
        }
    }
    return caracter;

}

int invertirBit(char bit){
    if(bit == 48) return 49;
    else return 48;
}

void contarBin(string binario, int contadores[2]){
    contadores[0] = 0;
    contadores[1] = 0;
    for(int contador = 0; contador < binario.size(); contador++) {
        contadores[binario.at(contador) - 48] += 1;
    }
}


