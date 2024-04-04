#include "../Headers/Banco.h"

int ***obtenerDatos(char *cuentasNormal){
    string aux;
    int intAux = 0;
    int indiceAux = 0;
    int *longitudes = new int[2];
    int ***datosGeneral = new int**[3];
    string datosNormal = binToString(decPrimerMetodo(2, decSegundoMetodo(2, capturarArchivo(cuentasNormal))));
    string datosAdmin = binToString(decPrimerMetodo(2, decSegundoMetodo(2, capturarArchivo("sudo.txt"))));
    int lenNormal = contarSeparador(datosNormal, "\r\n") + 1;
    int lenAdmin = contarSeparador(datosAdmin, "\r\n") + 1;
    int **cuentaNormal = new int*[lenNormal];
    int **cuentaAdmin = new int*[lenAdmin];
    datosGeneral[2] = new int*[1];
    longitudes[0] = lenNormal; longitudes[1] = lenAdmin;
    datosGeneral[0] = cuentaNormal;
    datosGeneral[1] = cuentaAdmin;
    datosGeneral[2][0] = longitudes;

    for(int cont = 0; cont < lenNormal; cont++){
        cuentaNormal[cont] = new int[2];
        while(intAux != datosNormal.size()){
            if(datosNormal.at(intAux) == ','){
                cuentaNormal[cont][indiceAux] = stoi(aux);
                aux = "";
                indiceAux++;
            }
            else if(datosNormal.at(intAux) == '\r'){
                break;
            }
            else{
                aux += datosNormal.at(intAux);
            }
            intAux++;
        }
        cuentaNormal[cont][indiceAux] = stoi(aux);
        indiceAux = 0;
        aux = "";
        intAux += 2;
    }
    indiceAux = 0;
    intAux = 0;

    for(int cont = 0; cont < lenAdmin; cont++){
        cuentaAdmin[cont] = new int[2];
        while(intAux != datosAdmin.size()){
            if(datosAdmin.at(intAux) == ','){
                cuentaAdmin[cont][indiceAux] = stoi(aux);
                aux = "";
                indiceAux++;
            }
            else if(datosAdmin.at(intAux) == '\r'){
                break;
            }
            else{
                aux += datosAdmin.at(intAux);
            }
            intAux++;
        }
        cuentaAdmin[cont][indiceAux] = stoi(aux);
        indiceAux = 0;
        aux = "";
        intAux += 2;
    }
    return datosGeneral;
}

int *existeUsuario(int **cuentasNormal, int **cuentasAdmin, int documento, int *longitudArreglos){
    int *arreglo = new int[2];
    arreglo[0] = -1;
    arreglo[1] = -1;
    for(int cont = 0; cont < longitudArreglos[0]; cont++){
        if(cuentasNormal[cont][0] == documento){
            arreglo[0] = cont;
            break;
        }
    }

    for(int cont = 0; cont < longitudArreglos[1]; cont++){
        if(cuentasAdmin[cont][0] == documento){
            arreglo[1] = cont;
            break;
        }
    }



    return arreglo;
}

void guardarDatos(int **cuentasUsu, int lenCuentas, char *archivo){
    string cadena;
    string encriptacion;
    for(int cont = 0; cont < lenCuentas; cont++){
        for(int cont2 = 0; cont2 < 3; cont2++){
            cadena += to_string(cuentasUsu[cont][cont2]);
            if(cont2 != 2) cadena += ',';
        }
        if(cont != lenCuentas - 1) cadena += "\r\n";
    }

    encriptacion = codSegundoMetodo(2, codPrimerMetodo(2, stringToBin(cadena)));
    escribirArchivo(encriptacion.size(), archivo, encriptacion);
}

int*** anadirCuenta(int ***datos,  int documento, int clave, int saldo){
    int *cuenta = new int[3];
    cuenta[0] = documento; cuenta[1] = clave; cuenta[2] = saldo;

    int ***datosNuevos = new int**[3];

    datosNuevos[0] = new int*[datos[2][0][0] + 1];
    datosNuevos[2] = datos[2]; datosNuevos[1] = datos[1];
    for(int cont = 0; cont < datos[2][0][0]; cont++) {
        datosNuevos[0][cont] = datos[0][cont];
    }
    datosNuevos[0][datos[2][0][0]] = cuenta;
    datosNuevos[2][0][0]++;
    return datosNuevos;
}
