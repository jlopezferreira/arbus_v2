#include <iostream>
#include "Arbus.h"

// Contructor
template <typename T>
Arbus<T>::Arbus()
{
    raiz = NULL;
}

// Destructor
template <typename T>
Arbus<T>::~Arbus()
{
    raiz = NULL;
}

// Agregar elementos
template <typename T>
void Arbus<T>::agregar(T elemento)
{
    if (raiz == NULL) {
        crearNodo(elemento, raiz);
    } else {
        crearArbol(raiz, elemento);
    }
}

template <typename T>
void Arbus<T>::crearArbol(Nodo * & raiz, T elemento)
{
    if (elemento < raiz->elemento) {
        if (raiz->izq != NULL) {
            crearArbol(raiz->izq, elemento);
        } else {
            crearNodo(elemento, raiz->izq);
        }
    } else if (elemento > raiz->elemento) {
        if (raiz->der != NULL) {
            crearArbol(raiz->der, elemento);
        } else {
            crearNodo(elemento, raiz->der);
        }
    }
}

template <typename T>
void Arbus<T>::crearNodo(T elemento, Nodo * & padre)
{
    Nodo * nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    padre = nuevo;
}

// Vacio
template <typename T>
bool Arbus<T>::esVacio()
{
    return raiz == NULL;
}
// Pertenece
template <typename T>
bool Arbus<T>::pertenece(T elemento)
{
    if (esVacio())
        return false;
    else {
        if (elemento < raiz->elemento)
            return subIzquierdo()->pertenece(elemento);
        else if (elemento > raiz->elemento)
            return subDerecho()->pertenece(elemento);
        else
            return true;
    }
}

template <typename T>
bool Arbus<T>::esHoja()
{
    return raiz->izq == NULL && raiz->der == NULL;
}

// Cantidad de elementos
template <typename T>
int Arbus<T>::cantidadElementos()
{
    int contador;
    if (esVacio())
        contador = 0;
    else {
        contador = 1;
        contador += subIzquierdo()->cantidadElementos();
        contador += subDerecho()->cantidadElementos();
    }
    return contador;
}

template <typename T>
int Arbus<T>::profundidad()
{
    int profundidad;
    if (esVacio()) {
        profundidad = 0;
    } else {
        profundidad = 1;
        int izqProf = subIzquierdo()->profundidad();
        int derProf = subDerecho()->profundidad();
        if (izqProf <= derProf)
            profundidad += derProf;
        else
            profundidad += izqProf;
    }
    return profundidad;
}

template <typename T>
Arbus<T> * Arbus<T>::subIzquierdo() const
{
    Arbus<T> * subIzq = new Arbus;
    subIzq->raiz = raiz->izq;
    return subIzq;
}

template <typename T>
Arbus<T> * Arbus<T>::subDerecho() const
{
    Arbus<T> * subDer = new Arbus;
    subDer->raiz = raiz->der;
    return subDer;
}

template <typename T>
void Arbus<T>::mostrarFrontera()
{
    if (!esVacio()) {
        if (esHoja()) {
            std::cout << raiz->elemento << std::endl;
        } else {
            subIzquierdo()->mostrarFrontera();
            subDerecho()->mostrarFrontera();
        }
    }
}

template <typename T>
void Arbus<T>::mostrarEnOrden()
{
    if (!esVacio()) {
        subIzquierdo()->mostrarEnOrden();
        std::cout << raiz->elemento << std::endl;
        subDerecho()->mostrarEnOrden();
    }
}

template class Arbus<int>;
