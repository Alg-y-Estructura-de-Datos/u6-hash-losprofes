#include <iostream>
#include <string>
#include "../Hash/HashMap.h" // Asegúrate de que la ruta sea correcta

using namespace std;

// Función hash simple para cadenas
unsigned int hashString(string clave) { // Cambiado a string en lugar de const string&
    unsigned int hash = 0;
    for (char c : clave) {
        hash += c;
    }
    return hash;
}

int main() {
    unsigned int tamanoTabla = 10; // Tamaño de la tabla hash
    HashMap<string, string> diccionario(tamanoTabla, hashString);

    int opcion;
    string palabra, significado;

    do {
        cout << "1. Agregar palabra\n";
        cout << "2. Buscar significado\n";
        cout << "3. Eliminar palabra\n";
        cout << "4. Ver todas las palabras\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la palabra: ";
                cin >> palabra;
                cout << "Ingrese el significado: ";
                cin.ignore(); // Para ignorar el salto de línea
                getline(cin, significado);
                diccionario.put(palabra, significado);
                cout << "Palabra agregada correctamente.\n";
                break;

            case 2:
                cout << "Ingrese la palabra a buscar: ";
                cin >> palabra;
                try {
                    significado = diccionario.get(palabra);
                    cout << "Significado de " << palabra << ": " << significado << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Palabra no encontrada.\n";
                    } else {
                        cout << "Error: Conflicto en la búsqueda.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese la palabra a eliminar: ";
                cin >> palabra;
                diccionario.remove(palabra);
                cout << "Palabra eliminada correctamente (si existia).\n";
                break;

            case 4:
                cout << "Todas las palabras en el diccionario:\n";
                diccionario.print(); // Imprimir todas las entradas
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }

        cout << endl;

    } while (opcion != 0);

    return 0;
}
