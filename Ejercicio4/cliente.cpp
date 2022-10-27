#include "./utils/commons.hpp"
#include "./utils/colors.hpp"

// Colors
Color::Modifier red(Color::FG_RED);
Color::Modifier def(Color::FG_DEFAULT);
Color::Modifier blu(Color::FG_BLUE);
// Function declarations
void mostrarOpciones();

int main(int argc, char *argv[])
{

    cout << "Inicio de ejecicion del cliente..." << endl;
    sleep(2);

    int opcionElegida;

    mostrarOpciones();
    cin >> opcionElegida;
    // Validar opcion elegida

    while (opcionElegida != 0)
    {
        cout << "ejecuto" << endl;


        
       

        //Desarrollar logica del ejercicio



        //Final del programa - vuelve a preguntar si quiero hacer mas consultas
        sleep(2);
        mostrarOpciones();
        cin >> opcionElegida;
    }
}

void mostrarOpciones()
{
    system("clear");
    cout << blu << "\n\tA CONTINUACION VERA UNA LISTA DE OPCIONES A REALIZAR \t\t\n\n " << def << endl;

    cout << "1- ALTA" << endl;
    cout << "2- BAJA" << endl;
    cout << "3- CONSUTA" << endl;
    cout << "0- SALIR" << endl;

    cout << "\nIngrese la opcion que desea realizar: ";
}
