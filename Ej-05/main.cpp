#include <iostream>
#include "../Hash/HashMap.h"

using namespace std;

void menu() {
    cout << "1. Agregar libro" << endl;
    cout << "2. Buscar libro" << endl;
    cout << "3. Eliminar libro" << endl;
    cout << "4. Mostrar todos los libros" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opcion: ";
}

int main() {
    HashMap<int, string> biblioteca(10);  // HashMap de 10 posiciones
    int opcion, isbn;
    string titulo;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ISBN del libro: ";
                cin >> isbn;
                cout << "Ingrese título del libro: ";
                cin >> titulo;
                try {
                    biblioteca.put(isbn, titulo);
                    cout << "Libro agregado con exito!" << endl;
                } catch (int e) {
                    cout << "Error: Colision al agregar libro." << endl;
                }
                break;
            case 2:
                cout << "Ingrese ISBN del libro: ";
                cin >> isbn;
                try {
                    cout << "Libro: " << biblioteca.get(isbn) << endl;
                } catch (int e) {
                    cout << "Error: Libro no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Ingrese ISBN del libro a eliminar: ";
                cin >> isbn;
                try {
                    biblioteca.remove(isbn);
                    cout << "Libro eliminado con exito!" << endl;
                } catch (int e) {
                    cout << "Error: Libro no encontrado." << endl;
                }
                break;
            case 4:
                biblioteca.print();
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
