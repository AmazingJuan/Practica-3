#include "../Headers/Utilidades.h"
#include "../Headers/Validacion.h"
int menuOpcion(string mensaje, string* opciones, int lenOpcion){
    bool bandera = true;
    bool error = false;
    string entrada = "";
    while(bandera){
        limpiarPantalla();
        cout << mensaje;
        if(!error) cout << "Escoja la opcion que desee: ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar la opcion por favor: ";
        getline(cin, entrada);
        if(validarOpcion(entrada, opciones, lenOpcion)) return stoi(entrada);
        else error = true;
    }
}

string menuEntrada(string mensaje, bool isNumero, int longMin, int longMax, bool isSaldo){
    bool bandera = true;
    bool error = false;
    string entrada = "";
    while(bandera){
        limpiarPantalla();
        cout << mensaje;
        if(!error) cout << "Ingrese la entrada que se le pide: ";
        else cout << "Ingreso una entrada incorrecta, vuelva a ingresar la entrada por favor: ";
        getline(cin, entrada);
        if(validarEntrada(entrada, isNumero, longMin, longMax, isSaldo)) return entrada;
        else error = true;
    }
}
