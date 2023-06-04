
#include <iostream>
#include "contact.hpp"

class Nodo {
public:
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

class ArbolBinario {
private:
    Nodo* raiz;

public:
    ArbolBinario() {
        raiz = nullptr;
    }

    Nodo* obtenerRaiz() {
        return raiz;
    }

    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            nodo = new Nodo(valor);
        } else if (valor < nodo->dato) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }
        return nodo;
    }

    void imprimirEnOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            imprimirEnOrden(nodo->izquierda);
            std::cout << nodo->dato << " ";
            imprimirEnOrden(nodo->derecha);
        }
    }

    void imprimirArbol() {
        imprimirEnOrden(raiz);
        std::cout << std::endl;
    }
};


