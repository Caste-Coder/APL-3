// Encabezado

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
#include <sys/wait.h>

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

memoria* obtenerDatosCompartidos() {
    
    int idMemoria = shm_open(ArchMC, O_RDWR, 0600);

    memoria* mem = (memoria*)mmap(NULL, sizeof(memoria), PROT_READ | PROT_WRITE, MAP_SHARED, idMemoria, 0);

    close(idMemoria);
    
    return mem;
}

void liberarMemoriaCompartida() {
    munmap(obtenerDatosCompartidos(),sizeof(memoria));
}



int main(int argc, char *argv[])
{
    // Validar datos y Ayuda

    // Conexion

    int idMemoria;

    if (!inicializarMemoria())
    {
        cerr << "Solo una instancia de servidor se puede ejecutar a la vez" << endl;
        exit(1);
    }
    cout << "esperando" << endl;
    sleep(5);
    cout << "esperando" << endl;
    memoria* datos = obtenerDatosCompartidos();

    cout << "Castrado: " << datos->castrado << "Sexo:  " << datos->sexo << endl;
    // liberarMemoriaCompartida();
    // shm_unlink(ArchMC);

    return 0;
}
