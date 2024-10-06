#include <iostream>
#include "../Hash/HashMapList.h"

using namespace std;

struct Producto {
    std::string nombre;
    double precio;

    // Constructor por defecto
    Producto() : nombre(""), precio(0.0) {} // Inicializa con valores predeterminados

    // Constructor para facilitar la creación de productos
    Producto(std::string n, double p) : nombre(n), precio(p) {}

    // Método para obtener una representación del producto
    std::string getValor() const {
        return "Nombre: " + nombre + ", Precio: " + std::to_string(precio);
    }
};

// Sobrecarga del operador << para imprimir productos
std::ostream& operator<<(std::ostream& os, const Producto& p) {
    os << "Nombre: " << p.nombre << ", Precio: " << p.precio;
    return os;
}

// Función hash simple para los códigos de productos (clave)
unsigned int hashFunc(unsigned int clave) {
    return clave;  // Retorna el valor de la clave como el índice hash
}

int main() {
    unsigned int tamanioTabla = 10;  // Tamaño de la tabla hash
    HashMapList<unsigned int, Producto> mapaProductos(tamanioTabla, hashFunc);

    int opcion;
    do {
        cout << "\nSistema de Gestion de Inventario\n";
        cout << "1. Agregar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Buscar producto\n";
        cout << "4. Mostrar lista completa de productos\n";
        cout << "5. Verificar si el inventario esta vacio\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                unsigned int codigo;
                string nombre;
                double precio;
                cout << "Ingrese codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese nombre del producto: ";
                cin.ignore();  // Limpiar el buffer
                getline(cin, nombre);
                cout << "Ingrese precio del producto: ";
                cin >> precio;
                mapaProductos.put(codigo, Producto(nombre, precio));
                cout << "Producto agregado con exito.\n";
                break;
            }
            case 2: {
                unsigned int codigo;
                cout << "Ingrese codigo del producto a eliminar: ";
                cin >> codigo;
                try {
                    mapaProductos.remove(codigo);
                    cout << "Producto eliminado con exito.\n";
                } catch (int e) {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 3: {
                unsigned int codigo;
                cout << "Ingrese codigo del producto a buscar: ";
                cin >> codigo;
                cout << "Producto encontrado:\n";
                try {
                    mapaProductos.getList(codigo); // Llama a getList para imprimir el producto
                } catch (int e) {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 4: {
                cout << "Lista completa de productos: \n";
                mapaProductos.print();
                break;
            }
            case 5: {
                if (mapaProductos.esVacio()) {
                    cout << "El inventario esta vacio.\n";
                } else {
                    cout << "El inventario NO esta vacio.\n";
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
