#include "../Headers/Programas.h"
#include "../Headers/Utilidades.h"
#include "../Headers/Menus.h"
#include "../Headers/Codificacion.h"
#include "../Headers/Decodificacion.h"
#include "../Headers/Archivos.h"
#include "../Headers/Banco.h"

void criptografia(){
    bool bandera = true;
    int semilla = 0;
    int metodo = 0;
    string auxString = "";
    string arcEntrada = "../Practica-3/Inputs/";
    string arcSalida = "../Practica-3/Outputs/";
    int opcion = 0;
    string entrada = "";
    string *opciones = crearArray("1 2 3", 3);
    string *opcionesMet = crearArray("1 2", 2);

    while(bandera){
        if(opcion == 0){
            opcion = menuOpcion(obtenerMensaje("criptografia"), opciones, 3);
        }
        else if(opcion == 1){
            metodo = menuOpcion(obtenerMensaje("metodos"), opcionesMet, 2);
            arcEntrada += menuEntrada(obtenerMensaje("entrada"), false, 0, -1, false);
            arcSalida += menuEntrada(obtenerMensaje("salida"), false, 0, -1, false);
            char *aux = new char[arcEntrada.size() + 1];
            stringToChar(arcEntrada, aux);
            auxString = stringToBin(capturarArchivo(aux));
            semilla = stoi(menuEntrada(obtenerMensaje("semilla"), true, 1, -1, false));
            if(auxString.size() % semilla == 0){
                if(metodo == 1){
                    auxString = codPrimerMetodo(semilla, auxString);
                }
                else if(metodo == 2){
                   auxString = codSegundoMetodo(semilla, stringToBin(capturarArchivo(aux)));
                }
                delete [] aux;
                aux = new char[arcSalida.size() + 1];
                stringToChar(arcSalida, aux);
                escribirArchivo(auxString.size(), aux, auxString);
                opcion = 0;
                arcEntrada = "../Practica-3/Inputs/";
                arcSalida = "../Practica-3/Outputs/";
            }
            else{
                limpiarPantalla();
                cout << obtenerMensaje("error") + "Lo sentimos, no podemos encriptar con esta semilla...";
                congelarPantalla(5);
                opcion = 0;
            }

        }
        else if(opcion == 2){
            metodo = menuOpcion(obtenerMensaje("metodos"), opcionesMet, 2);
            arcEntrada += menuEntrada(obtenerMensaje("entrada"), false, 0, -1, false);
            arcSalida += menuEntrada(obtenerMensaje("salida"), false, 0, -1, false);
            char *aux = new char[arcEntrada.size() + 1];
            stringToChar(arcEntrada, aux);
            auxString = capturarArchivo(aux);
            semilla = stoi(menuEntrada(obtenerMensaje("semilla"), true, 1, -1, false));
            if(auxString.size() % semilla == 0){
                if(metodo == 1){
                    auxString = decPrimerMetodo(semilla, auxString);
                }
                else if(metodo == 2){
                    auxString = decSegundoMetodo(semilla, auxString);
                }
                delete [] aux;
                aux = new char[arcSalida.size() + 1];
                stringToChar(arcSalida, aux);
                auxString = binToString(auxString);
                escribirArchivo(auxString.size(), aux, auxString);
                opcion = 0;
            }
            else{
                limpiarPantalla();
                cout << obtenerMensaje("error") + "Lo sentimos, no podemos encriptar con esta semilla...";
                congelarPantalla(5);
                opcion = 0;
            }
        }
        else bandera = false;
        arcEntrada = "../Practica-3/Inputs/";
        arcSalida = "../Practica-3/Outputs/";
    }
    delete [] opciones;
    delete [] opcionesMet;
}

void banco(){
    int ***datos = obtenerDatos("../Practica-3/Inputs/usuarios.txt");
    int *arregloExiste = nullptr;
    int *sesion = nullptr;
    int indice = -2;
    bool bandera = true;
    bool aux = false;
    string *opciones = crearArray("1 2 3", 3);
    int opcion;
    int opcionDentro;
    int opcAdm;
    string entrada;
    int documento = -1;
    int saldo;
    int retirar;
    int clave;

    while(bandera){
        if(documento == -1 && sesion == nullptr){
            opcion = menuOpcion(obtenerMensaje("bienvenidaBanco"), opciones, 2);
        }
        if(opcion == 1){
            if(sesion == nullptr){
                if(!aux){
                    documento = stoi(menuEntrada("\n\n" + obtenerMensaje("documento") + "\n\nDocumento de la cuenta...\n\n", true, 8, 10, false));
                    arregloExiste = existeUsuario(datos[0], datos[1], documento, datos[2][0]);
                    if(arregloExiste[0] != -1 || arregloExiste[1] != -1) aux = true;
                    else documento = -1;
                }
                if(arregloExiste[1] != -1 || arregloExiste[0] != -1){
                    clave = stoi(menuEntrada(obtenerMensaje("clave") + "\n\nClave de su cuenta...\n\n", true, 4, 4, false));
                    arregloExiste[0] == -1 ? indice = 1 : indice = 0;
                    if(datos[indice][arregloExiste[indice]][1] == clave){
                        sesion = datos[indice][arregloExiste[indice]];
                        documento = -1;
                    }
                    else{
                        limpiarPantalla();
                        cout << obtenerMensaje("error") + "Lo sentimos, esta clave no corresponde a la guardada en la base de datos, ingresela de nuevo...";
                        congelarPantalla(5);
                    }
                }
                else{
                    limpiarPantalla();
                    cout << obtenerMensaje("error") + "Lo sentimos, esta cuenta no se encuentra registrada en el sistema, volviendo al menu del banco...";
                    congelarPantalla(5);
                }
            }
            else{
                if(arregloExiste[1] == -1){
                    opcionDentro = menuOpcion(obtenerMensaje("menuUsu") , opciones, 3);
                    if(opcionDentro == 1){
                        if(sesion[2] - 1000 >= 0){
                            sesion[2] -= 1000;
                            menuOpcion(obtenerMensaje("consultarSaldo") + "Bienvenido a la consulta de saldo, su saldo despues de efectuar el cobro es: " + to_string(sesion[2]) + "\n\n1. Si quiere volver al menu de usuario presione esta opcion.\n\n" ,opciones, 1);
                            guardarDatos(datos[0], datos[2][0][0], "usuarios.txt");
                        }
                        else{
                            limpiarPantalla();
                            cout << obtenerMensaje("error") + "Lo sentimos, no tiene saldo suficiente para consultar saldo, volviendo al menu de usuario...";
                            congelarPantalla(5);
                        }
                    }
                    else if (opcionDentro == 2){
                        if(sesion[2] - 1000 >= 0){
                            retirar = stoi(menuEntrada(obtenerMensaje("consultarSaldo") + "Bienvenido al retiro de saldo, ingrese el monto que desea retirar, asegurese de que no sobrepase el monto total que puede retirar es: " + to_string(sesion[2] - 1000) + "\n\n", true, 1, -1, true));
                            if(sesion[2] - 1000 - retirar >= 0 && retirar > 0){
                                sesion[2] -= 1000;
                                guardarDatos(datos[0], datos[2][0][0], "usuarios.txt");
                            }
                            else{
                                limpiarPantalla();
                                cout << obtenerMensaje("error") + "Lo sentimos, ingreso un saldo invalido, volviendo al menu de usuario...";
                                congelarPantalla(5);
                            }
                        }
                        else{
                            limpiarPantalla();
                            cout << obtenerMensaje("error") + "Lo sentimos, no tiene saldo suficiente para retirar, volviendo al menu de usuario...";
                            congelarPantalla(5);
                        }
                    }
                    else{
                        sesion = nullptr;
                        documento = -1;
                        aux = false;
                    }
                }
                else{
                    if(documento == -1){
                        opcAdm = menuOpcion(obtenerMensaje("admin"), opciones, 2);
                    }
                    if(opcAdm == 1){
                        documento = stoi(menuEntrada(obtenerMensaje("documento") + "\n\nDocumento de la cuenta...\n\n", true, 8, 10, false));
                        if(existeUsuario(datos[0], datos[1], documento, datos[2][0])[0] == -1 && existeUsuario(datos[0], datos[1], documento, datos[2][0])[0] == -1){
                            clave = stoi(menuEntrada(obtenerMensaje("clave") + "\n\nClave para el la cuenta con documento " + to_string(documento) + "...\n\n", true, 4, 4, false));
                            saldo = stoi(menuEntrada(obtenerMensaje("saldo"), true, 1, -1, true));
                            datos = anadirCuenta(datos, documento, clave, saldo);
                            guardarDatos(datos[0], datos[2][0][0], "usuarios.txt");
                            documento = -1;
                        }
                        else{
                            limpiarPantalla();
                            cout << obtenerMensaje("error") + "Lo sentimos, este usuario ya esta creado en la base de datos, escoja otro por favor...";
                            congelarPantalla(5);
                        }
                    }
                    else{
                        sesion = nullptr;
                        aux = false;
                        documento = -1;
                    }
                }
            }

        }
        else if(opcion == 2){
            bandera = false;
        }
    }


}
