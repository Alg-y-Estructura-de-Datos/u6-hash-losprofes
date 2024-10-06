#include <iostream>
#include "../Hash/HashMapList.h"

using namespace std;

// Función hash simple para las matrículas (clave)
unsigned int hashFunc(unsigned int clave) {
    return clave;  // Retorna el valor de la clave como el índice hash
}

int main() {
    unsigned int tamanioTabla = 10;  // Tamaño de la tabla hash
    HashMapList<unsigned int, string> mapaEstudiantes(tamanioTabla, hashFunc);

    int opcion;
    do {
        cout << "\nSistema de Gestion de Estudiantes\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Eliminar estudiante\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Mostrar lista completa de estudiantes\n";
        cout << "5. Verificar si el sistema esta vacio\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                unsigned int matricula;
                string nombre;
                cout << "Ingrese numero de matricula: ";
                cin >> matricula;
                cout << "Ingrese nombre del estudiante: ";
                cin.ignore();  // Limpiar el buffer
                getline(cin, nombre);
                mapaEstudiantes.put(matricula, nombre);
                cout << "Estudiante agregado con exito.\n";
                break;
            }
            case 2: {
                unsigned int matricula;
                cout << "Ingrese numero de matricula del estudiante a eliminar: ";
                cin >> matricula;
                try {
                    mapaEstudiantes.remove(matricula);
                    cout << "Estudiante eliminado con exito.\n";
                } catch (int e) {
                    cout << "Estudiante no encontrado.\n";
                }
                break;
            }
            case 3: {
                unsigned int matricula;
                cout << "Ingrese numero de matricula del estudiante a buscar: ";
                cin >> matricula;
                try {
                    mapaEstudiantes.getList(matricula);
                } catch (int e) {
                    cout << "Estudiante no encontrado.\n";
                }
                break;
            }
            case 4: {
                cout << "Lista completa de estudiantes: \n";
                mapaEstudiantes.print();
                break;
            }
            case 5: {
                if (mapaEstudiantes.esVacio()) {
                    cout << "El sistema esta vacio.\n";
                } else {
                    cout << "El sistema NO esta vacio.\n";
                }
                break;
            }
            case 0: {
                cout << "Saliendo del sistema.\n";
                break;
            }
            default:
                cout << "Opción invalida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}
