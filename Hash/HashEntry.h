#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_

template <class K, class T>
class HashEntry
{
private:
    K clave;
    T valor;
public:
    HashEntry(K c, T v){
        clave = c;
        valor = v;
    }

    K getClave(){
        return clave;
    }
    void setClave(K c){
        clave = c;
    }

    T getValor(){
        return valor;
    }
    void setValor(T v){
        valor = v;
    }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_