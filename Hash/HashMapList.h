#ifndef U05_HASH_HASHMAP_HASHMAPLIST_H_
#define U05_HASH_HASHMAP_HASHMAPLIST_H_

#include "HashEntry.h"
#include "Lista.h"

//Tabla hash con manejo de colisiones usando listas enlazadas
template <class K, class T>
class HashMapList {
private:
    Lista<HashEntry<K, T>> **tabla;

    unsigned int tamanio;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMapList(unsigned int k);

    HashMapList(unsigned int k, unsigned int (*hashFuncP)(K clave));

    void getList(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    T get(K clave); // Declaración del método get

    ~HashMapList();

    bool esVacio();

    void print();
};

template <class K, class T>
HashMapList<K, T>::HashMapList(unsigned int k) {
    tamanio = k;
    tabla = new Lista<HashEntry<K, T>> *[tamanio];
    for(int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = hashFunc;
}

template <class K, class T>
HashMapList<K, T>::HashMapList(unsigned int k, unsigned int (*fp)(K)) {
    tamanio = k;
    tabla = new Lista<HashEntry<K, T>> *[tamanio];
    for(int i = 0; i < tamanio; i++) {
        tabla[i] = NULL;
    }
    hashFuncP = fp;
}

template <class K, class T>
HashMapList<K, T>::~HashMapList() {
    for(int i = 0; i < tamanio; i++) {
        if(tabla[i] != NULL) {
            delete tabla[i];
        }
    }
}

template <class K, class T>
void HashMapList<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if(tabla[pos] == NULL) {
        tabla[pos] = new Lista<HashEntry<K, T>>();
    }

    tabla[pos]->insertarUltimo( HashEntry<K, T>(clave, valor));
}

template <class K, class T>
void HashMapList<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio; // Calcular el índice hash

    // Verificar si hay una lista enlazada en esa posición
    if (tabla[pos] != nullptr) {

        while (!tabla[pos]->esVacia()) {
            tabla[pos]->remover(0); // Eliminar el primer nodo hasta que la lista esté vacía
        }

        delete tabla[pos]; // Liberar la memoria de la lista enlazada
        tabla[pos] = nullptr; // Establecer el puntero a NULL
    } else {
        throw std::runtime_error("La clave no se encontró en el sistema.");
    }
}

template <class K, class T>
T HashMapList<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % tamanio;

    if (tabla[pos] == NULL) {
        throw std::runtime_error("Clave no encontrada"); // O puedes lanzar la excepción 404
    }

    Nodo<HashEntry<K, T>> *nodo = tabla[pos]->getInicio();

    while (nodo != NULL) {
        if (nodo->getDato().getClave() == clave) {
            return nodo->getDato().getValor(); // Retornar el valor asociado a la clave
        }
        nodo = nodo->getSiguiente();
    }

    throw std::runtime_error("Clave no encontrada"); // O puedes lanzar la excepción 404
}

template <class K, class T>
bool HashMapList<K, T>::esVacio() {
    for(int i = 0; i < tamanio; i++) {
        if(tabla[i] != NULL) {
            return false;
        }
    }
    return true;
}

template <class K, class T>
unsigned int HashMapList<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}

template <class K, class T>
void HashMapList<K, T>::getList(K clave) { //Método que devuelve la lista según la clave que recibe
    unsigned int pos = hashFuncP(clave) % tamanio;

    if(tabla[pos] == NULL) {
        throw 404;
    }

    Nodo<HashEntry<K, T>> *aux = tabla[pos]->getInicio();

    while (aux != NULL) {
        std::cout << aux->getDato().getValor() << std::endl;
        aux = aux->getSiguiente();
    }
}

template <class K, class T>
void HashMapList<K, T>::print() {
    for(int i = 0; i < tamanio; i++) {
        if(tabla[i] != NULL) {
            std::cout << "Índice " << i << ": ";
            Nodo<HashEntry<K, T>> *aux = tabla[i]->getInicio();
            while (aux != NULL) {
                std::cout << "(" << aux->getDato().getClave() << ", " << aux->getDato().getValor() << ") ";
                aux = aux->getSiguiente();
            }
            std::cout << std::endl;
        }
    }
}

#endif // U05_HASH_HASHMAP_HASHMAPLIST_H_