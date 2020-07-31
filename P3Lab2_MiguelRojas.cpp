#include <iostream>
using namespace std;

int main(){

    char seguir = 's';
    int resp;
    while (seguir == 's'){
        cout << "   Menu" << endl
            << "[1]" << endl
            << "[2]" << endl
            << "Salir" << endl
            << "Seleccione una opcion: ";
        cin >> resp;
        cout << endl;
        switch (resp){
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            case 4:{
                cout << "Fin del Programa" << endl << endl;
                seguir = 'n';
                break;
            }
        default:
            cout << "Ingreso una opcion no valida." << endl << endl;
            break;
        }
    }
}