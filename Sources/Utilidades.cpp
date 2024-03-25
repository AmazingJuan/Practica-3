#include "../Headers/Utilidades.h"

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

bool stringInArray(string cadena, string* arreglo, int lenArreglo){
    for(int cont = 0; cont < lenArreglo; cont ++) if(cadena == arreglo[cont]) return true;
    return false;
}

string* crearArray(string entrada, int lenArray){
    string aux = "";
    int indice = 0;
    string *array = new string[lenArray];
    for(int contador = 0; contador < entrada.size(); contador++){
        if(entrada.at(contador) == ' '){
            array[indice] = aux;
            indice++;
            aux = "";
        }
        else aux += entrada.at(contador);
    }
    array[indice] = aux;
    return array;
}

void limpiarPantalla(){
    for(int contador = 0; contador < 50; contador++) cout << "\n";
}

string obtenerMensaje(string parametro){

    std::string bienvenida = "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n                                                                     \n                                                                     \n";
    bienvenida += "Bienvenido al menu principal de la Practica 3, usted tiene las siguientes opciones:\n\n1. Programa para codificar y decodificar.\n2. Programa de gestion de banco.\n3. Salir de la practica.\n\n";
    if(parametro == "bienvenida") return bienvenida;
}


