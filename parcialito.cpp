//
// Created by Matias on 10-May-26.
//
#include "Hash/HashMapList.h"
#include <iostream>
using namespace std;
#define Ej3

/**
 * eliminarClavesMenores ej1
 * @param tabla
 * @param k
 * @return
 */
int eliminarClavesMenores(HashMapList<int,int>& tabla, int k);

#ifdef Ej1
int main(){

    HashMapList<int,int> tabla(101);

    tabla.put(1,50);
    tabla.put(3,90);
    tabla.put(7,20);
    tabla.put(8,20);
    tabla.put(4,20);
    tabla.put(2,20);
    tabla.put(9,20);
    tabla.put(10,20);

    cout << "Tabla original:" << endl;
    tabla.print();


    int eliminados = eliminarClavesMenores(tabla,5);

    cout << endl;
    cout << "Eliminados: " << eliminados << endl;

    cout << endl;
    cout << "Tabla final:" << endl;
    tabla.print();

    return 0;
}
#endif

/*
 EJERCICIO 1
Consigna: Implementar una función:

int eliminarClavesMenores(HashMapList<int,int>& tabla, int k);

que elimine de una tabla hash de 101 elementos, todas las claves menores que k.

La función debe:

 1. devolver la cantidad de elementos eliminados
 2. utilizar try-catch
 3. trabajar únicamente con los métodos disponibles de la librería
 4. considerar que pueden existir colisiones

 */

int eliminarClavesMenores(HashMapList<int,int>& tabla, int k){

    int eliminados = 0;

    for(int i = 0; i < k; i++){

        try{

            tabla.remove(i);
            eliminados++;

        }
        catch(int e){

            // Error 404:
            cout << "la clave: " << i << " no existe"; //
        }
    }

    return eliminados;
}
/*
 EJERCICIO 2
Consigna: Implementar una función:

int copiarMayores(HashMapList<int,int>& origen,
                  HashMapList<int,int>& destino,
                  int k);

que copie de la hash origen a la hash destino, todos los elementos cuya clave
sea mayor que k.
Las dos tablas Hash tienen un tamanio de 1001 elementos.

La función debe:

1. devolver la cantidad de elementos copiados
2. NO eliminar elementos del hash original
3. utilizar try-catch
 */
/**
 * copiarMayores
 * @param origen
 * @param destino
 * @param k
 * @return
 */
int copiarMayores(HashMapList<int,int>& origen,
                  HashMapList<int,int>& destino,
                  int k);
#ifdef Ej2
int main(){

    HashMapList<int,int> origen(1001);
    HashMapList<int,int> destino(1001);

    origen.put(2,100);
    origen.put(7,50);
    origen.put(10,80);
    origen.put(15,20);

    cout << "Hash origen:" << endl;
    origen.print();

    int copiados = copiarMayores(origen,destino,8);

    cout << endl;
    cout << "Cantidad copiados: " << copiados << endl;

    cout << endl;
    cout << "Hash destino:" << endl;
    destino.print();

    return 0;
}
#endif


int copiarMayores(HashMapList<int,int>& origen,
                  HashMapList<int,int>& destino,
                  int k){

    int copiados = 0;

    for(int i = k + 1; i < 1001; i++){

        try{

            int valor = origen.get(i);

            destino.put(i, valor);

            copiados++;

        }
        catch(int e){

            // Error 404:
            // la clave no existe
        }
    }

    return copiados;
}


/*
EJERCICIO 3
Consigna: Implementar una función:

bool existeValor(HashMapList<int,int>& tabla, int valorBuscado);

que determine si existe al menos un elemento en la tabla hash cuyo valor
sea igual a valorBuscado. La tabla Hash es de 1001 elementos

La función debe:

1. devolver true si el valor existe
2. devolver false en caso contrario
3. utilizar try-catch de ser necesario

 */
/**
 * existeValor
 * @param tabla
 * @param valorBuscado
 * @return
 */
bool existeValor(HashMapList<int,int>& tabla, int valorBuscado);

#ifdef Ej3

int main(){

    HashMapList<int,int> tabla(1001);

    tabla.put(4,20);
    tabla.put(8,99);
    tabla.put(12,50);

    tabla.print();

    cout << endl;

    if(existeValor(tabla,99)){
        cout << "El valor existe" << endl;
    }
    else{
        cout << "El valor NO existe" << endl;
    }

    return 0;
}
#endif

bool existeValor(HashMapList<int,int>& tabla, int valorBuscado){

    for(int i = 0; i < 1001; i++){

        try{

            int valor = tabla.get(i);

            if(valor == valorBuscado){

                return true;
            }

        }
        catch(int e){

            // Error 404:
            // la clave no existe
        }
    }

    return false;
}