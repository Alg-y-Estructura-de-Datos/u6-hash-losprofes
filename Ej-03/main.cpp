#include <iostream>
#include "../Hash/HashMap.h"

using namespace std;

void menu() {
    cout << "1. Agregar producto" << endl;
    cout << "2. Buscar producto" << endl;
    cout << "3. Eliminar producto" << endl;
    cout << "4. Mostrar todos los productos" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opcion: ";
}

int main() {
    HashMap<int, string> productos(10);  // HashMap de 10 posiciones
    int opcion, codigo;
    string nombre;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese nombre del producto: ";
                cin >> nombre;
                try {
                    productos.put(codigo, nombre);
                    cout << "Producto agregado con exito!" << endl;
                } catch (int e) {
                    cout << "Error: Codigo de producto ya existe." << endl;
                }
                break;
            case 2:
                cout << "Ingrese codigo del producto: ";
                cin >> codigo;
                try {
                    cout << "Producto: " << productos.get(codigo) << endl;
                } catch (int e) {
                    cout << "Error: Producto no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Ingrese codigo del producto a eliminar: ";
                cin >> codigo;
                try {
                    productos.remove(codigo);
                    cout << "Producto eliminado con exito!" << endl;
                } catch (int e) {
                    cout << "Error: Producto no encontrado." << endl;
                }
                break;
            case 4:
                productos.print();
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
