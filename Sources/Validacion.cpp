#include "../Headers/Validacion.h"
#include "../Headers/Utilidades.h"
bool validarOpcion(string entrada, string *opciones, int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones);
}

bool validarEntrada(string entrada, bool isNumero, int longitudMin, int longMax, bool isSaldo){
    if(entrada.size() == 0 || entrada.size() < longitudMin) return false;

    if(isNumero){
        string numeros = "1234567890";
        for(int cont = 0; cont < entrada.size(); cont++){
            if(numeros.find(entrada.at(cont)) > numeros.size()) return false;
        }
        if(entrada == "0" && !isSaldo) return false;
    }

    if(longMax == -1) return true;
    else return entrada.size() <= longMax;

}
