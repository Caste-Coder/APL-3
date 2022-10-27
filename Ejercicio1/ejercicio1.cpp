#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits>
#include <vector>
#include <string.h>

using namespace std;

int mostrarAyuda(int, char *);
void infoProceso(int generacion, string tipo)
{
    cout << "Soy el proceso con PID " << getpid() << " y pertenezco a la generación Nº " << generacion << " Pid: " << getpid() << " Pid padre: " << getppid() << " Parentesco/Tipo: " << tipo << endl;
}

int main(int argc, char **argv)
{

    if (mostrarAyuda(argc, argv[1]))
    {
        exit(1);
    }

    pid_t hijo1 = fork(); // Creamos el primero hijo

    if (hijo1 > 0) // Padre hijo 1
    {
        infoProceso(1, "PADRE");

        pid_t hijo2 = fork(); // Creamos el segundo hijo
        if (hijo2 > 0)
        {
        }
        else
        {
            infoProceso(2, "HIJO");
            // Creo 2 nietos

            pid_t nieto1 = fork(); // Creamos primer nieto

            if (nieto1 > 0)
            { // Sigo en el hijo

                pid_t nieto2 = fork(); // Creamos segundo nieto
                if (nieto2 > 0)
                { // Sigo en el hijo
                }
                else
                { // Ya soy nieto
                    infoProceso(3, "NIETO");

                    // Este nieto va a tener 2 hijos que seran los bisnietos

                    pid_t bisnieto4 = fork();

                    if (bisnieto4 > 0)
                    {
                        pid_t bisnieto5 = fork();

                        if (bisnieto5 > 0)
                        {
                        }
                        else
                        { // Ya soy bisnieto
                            infoProceso(4, "BISNIETO");
                        }
                    }
                    else
                    { // Ya soy bisnieto
                        infoProceso(4, "BISNIETO");
                    }
                }
            }
            else
            { // Ya soy nieto
                infoProceso(3, "NIETO");

                // Este nieto va a tener 2 hijos que seran los bisnietos

                pid_t bisnieto2 = fork();

                if (bisnieto2 > 0)
                {
                    pid_t bisnieto3 = fork();

                    if (bisnieto3 > 0)
                    {
                    }
                    else
                    { // Ya soy bisnieto
                        infoProceso(4, "BISNIETO");
                        pid_t zombie2 = fork();

                        if (zombie2 > 0)
                        {

                        }
                        else
                        {
                            infoProceso(88, "ZOMBIE");
                            exit(1);
                        }
                    }
                }
                else
                { // Ya soy bisnieto
                    infoProceso(4, "BISNIETO");
                }
            }
        }
    }
    else
    {
        infoProceso(2, "HIJO");
        // Creo 1 nieto

        pid_t nieto3 = fork();

        if (nieto3 > 0)
        { // Sigo en el hijo
        }
        else
        { // Ya soy nieto
            infoProceso(3, "NIETO");

            // Este nieto va a tener 1 hijos que seran el bisnieto

            pid_t bisnieto1 = fork();

            if (bisnieto1 > 0)
            {
            }
            else
            { // Ya soy bisnieto
                infoProceso(4, "BISNIETO");

                pid_t zombie1 = fork();

                if (zombie1 > 0)
                {
                }
                else
                {
                    infoProceso(88, "ZOMBIE");
                    pid_t demonio = fork();

                    if (demonio > 0)
                    {
                        exit(1);
                    }
                    else
                    {
                        infoProceso(99, "DEMONIO");
                    }
                }
            }
        }
    }

    cin.get();

    return EXIT_SUCCESS;
}

int mostrarAyuda(int cantPar, char *cad)
{

    if (cantPar == 2 && (!strcmp(cad, "-h") || !strcmp(cad, "--help")))
    {
        cout << "HELP" << endl;
        cout << "NAME" << endl;
        cout << "    ejercicio1.exe" << endl;
        cout << "SYNOPSIS:" << endl;
        cout << "    ejercicio1.exe" << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "    Este programa se encarga de generar un arbol de procesos " << endl;
        return 1;
    }
    return 0;
}
