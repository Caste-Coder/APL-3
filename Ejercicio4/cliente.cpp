#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <threads.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <bits/stdc++.h>
#include <syslog.h>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/file.h>
#include <errno.h>
#include <ctype.h>

#define ArchMC "/MemoriaCompartida"
#define ArchTam 1024

typedef struct {
    char sexo;
    char castrado;
}memoria;

using namespace ::std;

bool inicializarMemoria()
{
    int idMemoria = shm_open(ArchMC, O_RDWR | O_CREAT | O_EXCL, 0600);
    if (idMemoria < 0)
    {
        close(idMemoria);
        return false;
    }
    ftruncate(idMemoria, sizeof(ArchMC));

    return true;
}

memoria* obtenerDatosCompartidos(size_t size) {
    
    int idMemoria = shm_open(ArchMC, O_CREAT | O_RDWR, 0600);

    memoria* mem = (memoria*)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, idMemoria, 0);

    
    return mem;
}


int mostrarAyuda(int cantPar, char *cad)
{
    if (cantPar < 2)
    {
        printf("Error en la cantidad de parametros, utilice ./cliente.exe -h para ver la ayuda \n");
    }
    

    if (cantPar == 2 && (!strcmp(cad, "-h") || !strcmp(cad, "--help")))
    {
        cout << "HELP" << endl;
        cout << "NAME" << endl;
        cout << "    cliente.exe" << endl;
        cout << "SYNOPSIS:" << endl;
        cout << "    cliente.exe" << endl;
        cout << "    Parametros requeridos:" << endl;
        cout << "    Alta" << endl;
        cout << "    Baja" << endl;
        cout << "    Consulta" << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "    Mediante este programa podemos realizar un ALTA, BAJA y CONSULTA de gatos. " << endl;
        return 1;
    }
    return 0;
}



int validarAlta(int cantidadDeParametros, char* parametros[]) {

    if (cantidadDeParametros == 5 && (!strcmp(parametros[1], "ALTA"))){ //Si entra es alta

        if(parametros[4] != "H" || parametros[4] != "M" ){
            printf("MOSTRAMOS LA VALIDACION DE PARAMETROS"); /////Modificar
            return 1;
        }
        
        if(parametros[5] != "CA" || parametros[5] != "CS" ){
            printf("MOSTRAMOS LA VALIDACION DE PARAMETROS"); /////Modificar
            return 1;
        }


    }

    if (cantidadDeParametros == 2 && (!strcmp(parametros[1], "BAJA"))){ //Si entra es baja

    }

    if ( (cantidadDeParametros == 1 || cantidadDeParametros == 2) && (!strcmp(parametros[1], "CONSULTA"))){ //Si entra es consulta

    }
    

    printf("ERROR DE PARAMETROS -> LLAMAR A FUNCION VERIFICACION DE PARAMETROS\n");
    return 1;

}

int main(int argc, char *argv[])
{
    memoria *dir_M_SERVER;

    //if (mostrarAyuda(argc, argv[1])) //Mostramos ayuda
     //   exit(1);



    //validarAlta(argc, argv);


    int idMemoria;
    void* punteroArchivo;

    memoria mascota;
    mascota.castrado='c';
    mascota.sexo='m';

    dir_M_SERVER = obtenerDatosCompartidos(sizeof(mascota));
    idMemoria = shm_open(ArchMC, O_RDWR , 0600);
    //ACA ESCRIBO
    memcpy(dir_M_SERVER, &mascota, sizeof(mascota)); //destino -> origen
    close(idMemoria);
}


