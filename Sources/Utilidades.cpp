#include "../Headers/Utilidades.h"
#include <thread>

short elevar(short numero, short potencia){
    short resultado = 1;
    for(short contador = 0; contador < potencia; contador++) resultado = resultado * numero;
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
    for(unsigned long long contador = 0; contador < binario.size(); contador += 8){
        cadenaAux = binario.substr(contador, 8);
        cadena += binToChar(cadenaAux);
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

void stringToChar(string cadena, char *caracter){
    int contador = 0;
    for(; contador < cadena.size(); contador++){
        caracter[contador] = cadena.at(contador);
    }
    caracter[contador] = '\0';
}

string* crearArray(string entrada, int lenArray){
    string aux = "";
    int indice = 0;
    string *array = new string[lenArray];
    for(unsigned long long contador = 0; contador < entrada.size(); contador++){
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

    string bienvenida = "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n                                                                     \n                                                                     \n";
    bienvenida += "Bienvenido al menu principal de la Practica 3, usted tiene las siguientes opciones:\n\n1. Programa para codificar y decodificar.\n2. Programa de gestion de banco.\n3. Salir de la practica.\n\n";
    string criptografia = "   _____          _           _                                     __   _         \n  / ____|        (_)         | |                                   / _| (_)        \n | |       _ __   _   _ __   | |_    ___     __ _   _ __    __ _  | |_   _    __ _ \n | |      | '__| | | | '_ \\  | __|  / _ \\   / _` | | '__|  / _` | |  _| | |  / _` |\n | |____  | |    | | | |_) | | |_  | (_) | | (_| | | |    | (_| | | |   | | | (_| |\n  \\_____| |_|    |_| | .__/   \\__|  \\___/   \\__, | |_|     \\__,_| |_|   |_|  \\__,_|\n                      | |                     __/ |                                \n                      |_|                    |___/                                 \n\n\n";
    criptografia  += "Bienvenido al menu de criptografia, usted tiene las siguientes opciones: \n\n1. Codificar.\n2. Decodificar.\n3. Volver al menu principal.\n\n";
    string entrada = "  ______           _                        _         \n |  ____|         | |                      | |        \n | |__     _ __   | |_   _ __    __ _    __| |   __ _ \n |  __|   | '_ \\  | __| | '__|  / _` |  / _` |  / _` |\n | |____  | | | | | |_  | |    | (_| | | (_| | | (_| |\n |______| |_| |_|  \\__| |_|     \\__,_|  \\__,_|  \\__,_|\n                                                      \n";
    string semilla = "   _____                      _   _   _         \n  / ____|                    (_) | | | |        \n | (___     ___   _ __ ___    _  | | | |   __ _ \n  \\___ \\   / _ \\ | '_ ` _ \\  | | | | | |  / _` |\n  ____) | |  __/ | | | | | | | | | | | | | (_| |\n |_____/   \\___| |_| |_| |_| |_| |_| |_|  \\__,_|\n                                                \n                                                \n";
    string metodos = "  __  __          _                 _               \n |  \\/  |        | |               | |              \n | \\  / |   ___  | |_    ___     __| |   ___    ___ \n | |\\/| |  / _ \\ | __|  / _ \\   / _` |  / _ \\  / __|\n | |  | | |  __/ | |_  | (_) | | (_| | | (_) | \\__ \\\n |_|  |_|  \\___|  \\__|  \\___/   \\__,_|  \\___/  |___/\n                                                     \n                                                     \n";
    metodos += "Usted dispone de los siguientes metodos para encriptar o desencriptar:\n\n1. Primer metodo.\n2. Segundo metodo.\n\n";
    string bienvenidaBanco = "  ____\n |  _ \\\n | |_) |   __ _   _ __     ___    ___  \n |  _ <   / _` | | '_ \\   / __|  / _ \ \n | |_) | | (_| | | | | | | (__  | (_) |\n |____/   \\__,_| |_| |_|  \\___|  \\___/ \n\n";
    bienvenidaBanco += "Bienvenido al sistema de banco, usted posee las siguientes opciones:\n\n1. Iniciar sesion.\n2. Volver al menu principal.\n\n";
    string documento = "  _____                                                      _           \n |  __ \\                                                    | |          \n | |  | |   ___     ___   _   _   _ __ ___     ___   _ __   | |_    ___  \n | |  | |  / _ \\   / __| | | | | | '_ ` _ \\   / _ \\ | '_ \\  | __|  / _ \\ \n | |__| | | (_) | | (__  | |_| | | | | | | | |  __/ | | | | | |_  | (_) |\n |_____/   \\___/   \\___|  \\__,_| |_| |_| |_|  \\___| |_| |_|  \\__|  \\___/ ";
    string clave = "   _____   _                        \n  / ____| | |                       \n | |      | |   __ _  __   __   ___ \n | |      | |  / _` | \\ \\ / /  / _ \\\n | |____  | | | (_| |  \\ V /  |  __/\n  \\_____| |_|  \\__,_|   \\_/    \\___|";
    string error = "  ______                              \n |  ____|                             \n | |__     _ __   _ __    ___    _ __ \n |  __|   | '__| | '__|  / _ \\  | '__|\n | |____  | |    | |    | (_) | | |   \n |______| |_|    |_|     \\___/  |_|   \n\n";
    string menuUsu = " _    _                                _         \n | |  | |                              (_)        \n | |  | |  ___   _   _    __ _   _ __   _    ___  \n | |  | | / __| | | | |  / _` | | '__| | |  / _ \\ \n | |__| | \\__ \\ | |_| | | (_| | | |    | | | (_) |\n  \\____/  |___/  \\__,_|  \\__,_| |_|    |_|  \\___/ \n\nBienvenido de vuelta, usted tiene las siguientes opciones (tenga presente que cualquier retiro o consulta de saldo tiene un valor de 1000 COP):\n\n1. Consultar saldo\n2. Retirar saldo\n3. Volver al menu del banco\n\n";
    string consultarSaldo = "   _____                                 _   _                       _____           _       _         \n  / ____|                               | | | |                     / ____|         | |     | |        \n | |        ___    _ __    ___   _   _  | | | |_    __ _   _ __    | (___     __ _  | |   __| |   ___  \n | |       / _ \\  | '_ \\  / __| | | | | | | | __|  / _` | | '__|    \\___ \\   / _` | | |  / _` |  / _ \\ \n | |____  | (_) | | | | | \\__ \\ | |_| | | | | |_  | (_| | | |       ____) | | (_| | | | | (_| | | (_) |\n  \\_____|  \\___/  |_| |_| |___/  \\__,_| |_|  \\__|  \\__,_| |_|      |_____/   \\__,_| |_|  \\__,_|  \\___/ \n\n";
    string retirarSaldo = "  _____           _     _                            _____           _       _         \n |  __ \\         | |   (_)                          / ____|         | |     | |        \n | |__) |   ___  | |_   _   _ __    __ _   _ __    | (___     __ _  | |   __| |   ___  \n |  _  /   / _ \\ | __| | | | '__|  / _` | | '__|    \\___ \\   / _` | | |  / _` |  / _ \\ \n | | \\ \\  |  __/ | |_  | | | |    | (_| | | |       ____) | | (_| | | | | (_| | | (_) |\n |_|  \\_\\  \\___|  \\__| |_| |_|     \\__,_| |_|      |_____/   \\__,_| |_|  \\__,_|  \\___/ \n\n";
    string admin = "                 _               _           _         _                        _                \n     /\\         | |             (_)         (_)       | |                      | |               \n    /  \\      __| |  _ __ ___    _   _ __    _   ___  | |_   _ __    __ _    __| |   ___    _ __ \n   / /\\ \\    / _` | | '_ ` _ \\  | | | '_ \\  | | / __| | __| | '__|  / _` |  / _` |  / _ \\  | '__|\n  / ____ \\  | (_| | | | | | | | | | | | | | | | \\__ \\ | |_  | |    | (_| | | (_| | | (_) | | |   \n /_/    \\_\\  \\__,_| |_| |_| |_| |_| |_| |_| |_| |___/  \\__| |_|     \\__,_|  \\__,_|  \\___/  |_|   \n\nBienvenido al menu de administrador, usted posee las siguientes opciones:\n\n1. Registrar usuario\n2. Volver al menu del banco.\n\n";
    string saldo = "   _____           _       _         \n  / ____|         | |     | |        \n | (___     __ _  | |   __| |   ___  \n  \\___ \\   / _` | | |  / _` |  / _ \\ \n  ____) | | (_| | | | | (_| | | (_) |\n |_____/   \\__,_| |_|  \\__,_|  \\___/ \n\nSaldo de la cuenta nueva...\n\n";
    string salida = "   _____           _   _       _         \n  / ____|         | | (_)     | |        \n | (___     __ _  | |  _    __| |   __ _ \n  \\___ \\   / _` | | | | |  / _` |  / _` |\n  ____) | | (_| | | | | | | (_| | | (_| |\n |_____/   \\__,_| |_| |_|  \\__,_|  \\__,_|\n\n";

    if(parametro == "bienvenida") return bienvenida;
    else if(parametro == "criptografia") return criptografia;
    else if(parametro == "entrada") return entrada;
    else if(parametro == "semilla") return semilla;
    else if(parametro == "metodos") return metodos;
    else if(parametro == "bienvenidaBanco") return bienvenidaBanco;
    else if(parametro == "documento") return documento;
    else if(parametro == "clave") return clave;
    else if(parametro == "error") return error;
    else if(parametro == "menuUsu") return menuUsu;
    else if(parametro == "consultarSaldo") return consultarSaldo;
    else if(parametro == "admin") return admin;
    else if(parametro == "saldo") return saldo;
    else if(parametro == "salida") return salida;
}

int contarSeparador(string cadena, string separador){
    int contAux = 0;
    for(unsigned long long cont = 0; cont < cadena.size(); cont++){
        if(cadena.at(cont) == separador.at(0)) {
            contAux++;
            cont += 2;
        }
    }
    return contAux;
}

void congelarPantalla(int segundos){ //Se usó el ejemplo dado en la siguiente pagina: https://en.cppreference.com/w/cpp/thread/sleep_for.
    this_thread::sleep_for(segundos * 1000ms);
}



