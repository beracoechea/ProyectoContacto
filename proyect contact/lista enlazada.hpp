#ifndef LISTA ENLAZADA_H_INCLUED
#define LISTA ENLAZADA_H_INCLUED
#include<iostream>
#include<string>
#include"nodos.h"
class CLista{
private:
    CNodo Inicio;
    CNodo Final;
public:
    CLista();
    ~CLista();
    void insertarInicio(Llamadas *ccontenido);
    void insertarFinal(Llamadas *ccontenido);
    void Vaciar();
    void Imprime();
    void Guardar();
    void Recuperar();



    bool isEmpty();

    int Size();

   Llamadas* EliminarInicio();
    Llamadas* EliminarFinal();


};
using namespace std;
CLista::CLista() {
  Inicio.pSiguiente = &Final;
  Final.pAnterior =& Inicio;

    }

CLista::~CLista() {
    }

void CLista::insertarInicio(Llamadas * cData ) {
     Inicio.insertarAdelante(cData);
    }

void CLista::insertarFinal(Llamadas *cData) {
 Final.pAnterior->insertarAdelante(cData);
    }

void CLista::Vaciar() {
   CNodo* p=Inicio.pSiguiente;
    CNodo* x;
    while (p != &Final) {
        x =p ;
        p = p->pSiguiente;
        delete x;
    }
    Inicio.pSiguiente = &Final;
    Final.pAnterior = &Inicio;
    cout<<"SE ELIMINO TODO CORRECTAMENTE"<<endl;
    }

void CLista::Imprime() {
    CNodo *p = Inicio.pSiguiente;
    while(p != &Final){
        cout<< p ->cContenido->toString()<<endl;
        p = p -> pSiguiente;
    }
    }

bool CLista::isEmpty() {
   if(Inicio.pSiguiente == &Final){
     return true;
   }
     return false;
    }

int CLista::Size() {
     CNodo *p = Inicio.pSiguiente;
  int nodos = 0;

      while(p != &Final){
            nodos++;
        p = p -> pSiguiente;
      }
  return nodos;
    }

Llamadas* CLista::EliminarInicio() {
return Inicio.eliminarSiguiente();
  }

Llamadas* CLista::EliminarFinal() {
 return Final.pAnterior->pAnterior->eliminarSiguiente();

    }

void CLista::Guardar(){
    ofstream archivo("datos.txt");
    if(archivo.is_open()){
            CNodo *p = Inicio.pSiguiente;
    while(p != &Final){
        archivo<<p -> cContenido->getTel()<< endl;
        archivo<<p -> cContenido->getTime()<< endl;
        archivo<<p -> cContenido->getEstado()<< endl;


        p = p -> pSiguiente;
    }

    }
    archivo.close();
}
void CLista::Recuperar(){
ifstream archivo("datos.txt");

    if(archivo.is_open()){
        string linea;
        int telefono;
        while(true){

        Llamadas* P=new Llamadas;

        getline(archivo,linea);//ID
        if(archivo.eof()){
            break;
        }
        telefono=stoi(linea);//conversion a entero
        P->setTel(telefono);


        getline(archivo,linea);//origen
        P->setTime(linea);

        getline(archivo,linea);//destino
        P->setEstado(linea);

        insertarInicio(P);
    }
    }
}

#endif // LISTA_H_INCLUED

