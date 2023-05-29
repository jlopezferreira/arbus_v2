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

public:
    Arbus(); // Constructor
    ~Arbus(); //Destructor
    void agregar(T elemento);
    bool esVacio();
    T raizArbus(); // pre: not esVacio
    bool pertenece(T elemento);
    int cantidadElementos();
    int profundidad();
    // Nodo * subIzquierdo(); // pre: not esVacio
    // Nodo * subDerecho(); // pre: not esVacio
    // bool eliminar(T elemento);
};

#endif // ARBUS_H_INCLUDED
