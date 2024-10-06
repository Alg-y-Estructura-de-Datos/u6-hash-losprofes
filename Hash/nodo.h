#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo {
private:
    T dato;
    Nodo<T> *siguiente;

public:
    Nodo(T d, Nodo<T> *s) : dato(d), siguiente(s) {}

    T getDato() {
        return dato;
    }

    void setDato(T d) {
        dato = d;
    }

    Nodo<T> *getSiguiente() {
        return siguiente;
    }

    void setSiguiente(Nodo<T> *s) {
        siguiente = s;
    }
};

#endif //NODO_H