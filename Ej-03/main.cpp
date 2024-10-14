#include <iostream>
#include "../Hash/HashMapList.h"

using namespace std;

void menu() {
    cout << "1. Registrar voto" << endl;
    cout << "2. Verificar voto" << endl;
    cout << "3. Eliminar voto" << endl;
    cout << "4. Mostrar todos los votos" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opcion: ";
}

int main() {
    HashMapList<int, string> votos(11);  // HashMap de 10 posiciones
    int opcion, id;
    string candidato;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ID del votante: ";
            cin >> id;
            cout << "Ingrese nombre del candidato: ";
            cin >> candidato;
            try {
                votos.put(id, candidato);
                cout << "Voto registrado con exito!" << endl;
            } catch (int e) {
                cout << "Error: Colision al registrar voto." << endl;
            }
            break;
            case 2:
                cout << "Ingrese ID del votante: ";
            cin >> id;
            try {
                cout << "Voto: " << votos.get(id) << endl;
            } catch (int e) {
                cout << "Error: Votante no encontrado." << endl;
            }
            break;
            case 3:
                cout << "Ingrese ID del votante a eliminar: ";
            cin >> id;
            try {
                votos.remove(id);
                cout << "Voto eliminado con exito!" << endl;
            } catch (int e) {
                cout << "Error: Votante no encontrado." << endl;
            }
            break;
            case 4:
                votos.print();
            break;
            case 5:
                cout << "Saliendo..." << endl;
            break;
            default:
                cout << "Opción invalida!" << endl;
        }

    } while (opcion != 5);

    return 0;
}