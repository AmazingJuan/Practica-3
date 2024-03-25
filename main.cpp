#include "./Headers/Utilidades.h"
#include "./Headers/Decodificacion.h"
#include "./Headers/Codificacion.h"
#include "./Headers/Menus.h"
#include "./Headers/Programas.h"

int main(){
    string entrada = "";
    int opcion = 0;
    string *array = nullptr;
    bool bandera = true;

    while(bandera){
        array = crearArray("1 2 3", 3);
        opcion = menuOpcion(obtenerMensaje("bienvenida"), array, 3);
        if(opcion == 1){
            criptografia();
        }
        else if(opcion == 2){
            banco();
        }
        else{
            bandera = false;
        }
    }
}
