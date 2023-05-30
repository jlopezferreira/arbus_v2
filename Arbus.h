#ifndef ARBUS_H_INCLUDED
#define ARBUS_H_INCLUDED

template <typename T>
class Arbus
{
private:
    // Definición de la estructura
    struct Nodo {
        T elemento;
        Nodo * izq;
        Nodo * der;
    };
    // Atributos de clase
    Nodo * raiz;
    // Método auxiliar
    void vaciar();
    void crearArbol(Nodo * & raiz, T elemento);
    void crearNodo(T elemento, Nodo * & padre);
    bool existeElemento(Nodo * raiz, T elemento);
    bool esHoja(Nodo * raiz);
    int contar(Nodo * raiz);

public:
    Arbus(); // Constructor
    ~Arbus(); //Destructor
    void agregar(T elemento);
    bool esVacio();
    bool pertenece(T elemento);
    int cantidadElementos();
    int profundidad();
    Arbus<T> * subIzquierdo() const; // pre: not esVacio
    Arbus<T> * subDerecho() const; // pre: not esVacio
    // T raizArbus(); // pre: not esVacio

    // bool eliminar(T elemento);
};

#endif // ARBUS_H_INCLUDED
