#ifndef NODOS_H_INCLUED
#define NODOS_H_INCLUED
#include"Llamadas.hpp"
class CNodo{
 private:
    CNodo* pSiguiente;
     CNodo*pAnterior;
     Llamadas* cContenido;
 public:

    void insertarAdelante(Llamadas* cData);
    Llamadas* eliminarSiguiente();
    friend class CLista;
 };



using namespace std;


void CNodo::insertarAdelante(Llamadas* cData)
{
  CNodo* pNuevo = new CNodo;

  pNuevo->pSiguiente = this -> pSiguiente;
  pNuevo-> pAnterior = this;
  this -> pSiguiente = pNuevo;
  this -> pSiguiente -> pSiguiente -> pAnterior =pNuevo;
  pNuevo -> cContenido = cData;
}

Llamadas* CNodo::eliminarSiguiente() {

    Llamadas* x;
    CNodo* p=this->pSiguiente;
    x = p->cContenido;
    this->pSiguiente = this ->pSiguiente->pSiguiente;
    this->pSiguiente->pAnterior = this;
    //preguntar

    delete p;
    return x;

}
#endif // NODOS_H_INCLUED


