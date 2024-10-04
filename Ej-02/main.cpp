#include <iostream>
#include "../Hash/HashMap.h"

using namespace std;

void menu() {
    cout << "1. Agregar empleado" << endl;
    cout << "2. Buscar empleado" << endl;
    cout << "3. Eliminar empleado" << endl;
    cout << "4. Mostrar todos los empleados" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opcion: ";
}

int main() {
    HashMap<int, string> empleados(10);  // HashMap de 10 posiciones
    int opcion, id;
    string nombre;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                cout << "Ingrese nombre del empleado: ";
                cin >> nombre;
                try {
                    empleados.put(id, nombre);
                    cout << "Empleado agregado con exito!" << endl;
                } catch (int e) {
                    cout << "Error: Codigo de empleado ya existe." << endl;
                }
                break;
            case 2:
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                try {
                    cout << "Empleado: " << empleados.get(id) << endl;
                } catch (int e) {
                    cout << "Error: Empleado no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Ingrese ID del empleado a eliminar: ";
                cin >> id;
                try {
                    empleados.remove(id);
                    cout << "Empleado eliminado con exito!" << endl;
                } catch (int e) {
                    cout << "Error: Empleado no encontrado." << endl;
                }
                break;
            case 4:
                empleados.print();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }

    } while (opcion != 5);

    return 0;
}
