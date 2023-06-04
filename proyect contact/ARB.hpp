#ifndef ARB_H_INCLUDED
#define ARB_H_INCLUDED
#include<exception>
#include<string>
#include<iostream>
#include<fstream>
#include<ostream>
#include"contact.hpp"



template<class T>
class BTree {
    private:
        std::ofstream archivoSalida;
        class Node {
            private:
                T* dataPtr;
                Node* left;
                Node* right;


            public:
                class Exception :public std::exception {
                    private:
                        std::string msg;
                    public:
                        explicit Exception(const char* message):msg(message) {}
                        explicit Exception(const std::string&message):msg(message) {}
                        virtual ~Exception()throw() {}
                        virtual const char* what()const throw() {
                            return msg.c_str();
                            }
                    };
                Node();
                Node(const T&);
                ~Node();

                T* getDataPtr()const;
                T getData()const;
                Node*&getLeft();
                Node*& getRight();

                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(Node*&);
                void setRight(Node*&);

            };
    public:
        typedef Node* Position;

    private:
        Position root;
        Position izq,der;
        void copyAll(Position&,Position&);
        void insertData(Position&,const T&);

        Position& findData(Position&, const T&);
        Position& getLowest(Position&);
        Position& getHighest(Position&);

        void PreOrder(Position&);
        void InOrder(Position&);
        void PostOrder(Position&);
        void deleteAll(Position&);
        void toString(Position&);
        void archivos(Position&,std::ofstream&);
        void recupera(Position&,std::ifstream&);
        ///AVL

        int getBalance(Position&);

        void doleftrot(Position&);
        void dorightrot(Position&);
        void dobleleft(Position&);
        void dobleright(Position&);

        void doBalancing(Position&);


    public:
        class Exception :public std::exception {
            private:
                std::string msg;
            public:
                explicit Exception(const char* message):msg(message) {}
                explicit Exception(const std::string&message):msg(message) {}
                virtual ~Exception()throw() {}
                virtual const char* what()const throw() {
                    return msg.c_str();
                    }
            };

        BTree();
        BTree(const BTree&);
        ~BTree();

        bool isEmpty()const;
        void copyAll(const BTree<T>&);
        void insertData(const T&);
        void deleteData(Position&);

        void retrieve (Position&) const;




        int getHeight(Position&);

        Position& findData(const T&);
        Position& getLowest();
        Position& getHighest();
        Position& getIzq();
        Position& getDer();

        bool isLeaf(Position&)const;

        void PreOrder();
        void InOrder();
        void PostOrder();
        int getHeight();
        void deleteAll();

        void toString();
        void archivo();
        void recuperar();


        BTree& operator = (const BTree&);
    };

///NODO
template<class T>
BTree<T>::Node::Node():dataPtr(nullptr),left(nullptr),right(nullptr) {}

template<class T>
BTree<T>::Node::Node(const T& e):dataPtr(new T(e)),left(nullptr),right(nullptr){
    if(dataPtr == nullptr) {
        throw Exception("MEMORIA NO DISPONIBLE");
        }
    }

template<class T>
BTree<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T*BTree<T>::Node::getDataPtr()const {
    return dataPtr;
    }

template<class T>
T BTree<T>::Node::getData()const {
    if(dataPtr == nullptr) {
        throw Exception("DATO INEXISTENTE");
        }
    return *dataPtr;
    }

template<class T>
typename BTree<T>::Position& BTree<T>::Node::getLeft() {
    return left;
    }

template<class T>
typename BTree<T>::Position& BTree<T>::Node::getRight() {
    return right;
    }


template<class T>
void BTree<T>::Node::setDataPtr(T*p) {
    dataPtr=p;
    }

template<class T>
void BTree<T>::Node::setData(const T&e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e))== nullptr) {
            throw Exception("MEMORIA NO DISPONIBLE");
            }
        }
    else {
        *dataPtr=e;
        }
    }

template<class T>
void BTree<T>::Node::setLeft(Position& p) {
    left =p;
    }

template <class T>
void BTree<T>::Node::setRight(Position& p) {
    right=p;
    }

///----------------------------------------BTree---------------------------------------------

template <class T>
BTree<T>::BTree(): root(nullptr) {}
template<class T>
void BTree<T>::copyAll(const BTree<T>& l) {
    Position aux= l.root;
     try {
        if((root=new Node(aux->getData()))==nullptr) {
            throw Exception("memoria no disponible, inData");
            }
        }
    catch(typename Node::Exception ex) {
        throw Exception(ex.what());
        }

    copyAll(aux->getLeft(), root->getLeft());
    copyAll(aux->getRight(), root->getRight());

    }

template<class T>
void BTree<T>::copyAll(Position& origin, Position& destination) {
    if(origin==nullptr)
    {
        return;
    }
    try {
        if((destination=new Node(origin->getData()))==nullptr) {
            throw Exception("memoria no disponible, inData");
            }
        }
    catch(typename Node::Exception ex) {
        throw Exception(ex.what());
        }

    copyAll(origin->getLeft(), destination->getLeft());
    copyAll(origin->getRight(), destination->getRight());
    }

template <class T>
BTree<T>::BTree(const BTree& t):root(nullptr) {
    copyAll(t);
    }

template<class T>
 BTree<T>::~BTree() {
    deleteAll();
    }

template<class T>
bool BTree<T>::isEmpty()const {
    return root==nullptr;
    }
template <class T>
void BTree<T>::insertData(const T& e) {
    insertData(root,e);
    }

template <class T>
void BTree<T>::insertData(Position& r, const T& e) {
    if(r == nullptr) {
        try {
            if((r = new Node(e))== nullptr) {
                throw Exception("MEMORIA NO DISPONIBLE");
                }
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    else {
        if(e< r->getData()) {
            insertData(r->getLeft(),e);
            }
        else {
            insertData(r->getRight(),e);
            }
                doBalancing(r);
        }
    }

    template<class T>
    void BTree<T>::deleteData(Position& r){
 Position aux(r);
 T sub;
 if(r==nullptr){
    return;
 }
 if(isLeaf(r)){
    delete r;
    r=nullptr;
 }
 else{
    if(aux->getLeft()==nullptr or aux->getRight()==nullptr){
        r=(aux->getLeft()==nullptr?aux->getRight():aux->getLeft());
        delete r;
    }
    else{
        sub=getHighest(r->getLeft())->getData();
        r->setData(sub);
        deleteData(getHighest(r->getLeft()));
    }
    doBalancing(r);
 }
 }

template<class T>
typename BTree<T>::Position& BTree<T>::getLowest(){
return getLowest(root);
}

template<class T>
typename BTree<T>::Position& BTree<T>::getLowest(Position&r){
if(r == nullptr or r->getLeft()== nullptr){
    return r;
}

return getLowest(r->getLeft());
}

template<class T>
typename BTree<T>::Position& BTree<T>::getHighest(){
return getHighest(root);
}

template<class T>
typename BTree<T>::Position& BTree<T>::getHighest(Position&r){
if(r == nullptr or r->getRight()== nullptr){
    return r;
}

return getHighest(r->getRight());
}

template<class T>
bool BTree<T>::isLeaf(Position&r)const{
return r!= nullptr and r->getLeft()==r->getRight();
}

template<class T>
int BTree<T>::getHeight(){
return getHeight(root);
}

template<class T>
int BTree<T>::getHeight(Position& r){
if(r == nullptr){
    return 0;
}
int lH(getHeight(r->getLeft()));
int rH(getHeight(r->getRight()));
return (lH>rH? lH: rH)+1;
}

template <class T>
void BTree<T>::PreOrder(){
PreOrder(root,archivo);
}

template<class T>
void BTree<T>::PreOrder(Position &r){
if(r == nullptr){
    return;
}
std::cout<<r->getData()<<"\t";
PreOrder(r->getLeft(),archivo);
PreOrder(r->getRight(),archivo);
}

template <class T>
void BTree<T>::InOrder(){
InOrder(root);
}

template<class T>
void BTree<T>::InOrder(Position &r){
if(r == nullptr){
    return;
}
InOrder(r->getLeft());
std::cout<<r->getData()<<"\t";
InOrder(r->getRight());
}

template <class T>
void BTree<T>::PostOrder(){
PostOrder(root);
}

template<class T>
void BTree<T>::PostOrder(Position& r){
if(r == nullptr){
    return;
}
PostOrder(r->getLeft());
PostOrder(r->getRight());
std::cout<<r->getData()<<"\t";
}

template <class T>
void BTree<T>::deleteAll(){
        deleteAll(root);
        root = nullptr;
}

template<class T>
void BTree<T>::deleteAll(Position& r){

if(r == nullptr){
    return;
}

deleteAll(r->getLeft());
deleteAll(r->getRight());
Position aux(r);
delete aux;

}

template<class T>
BTree<T>&BTree<T>::operator=(const BTree& t){
deleteAll();

copyAll(t);

return *this;
}
template <class T>
void BTree<T>::toString(){
 toString(root);
}

template <class T>
void BTree<T>::toString(Position &r) {
 std::string result;
if(r == nullptr){
    return;
}
        toString(r->getLeft());
        result+= r->getData().toString()+"\n";std::cout<<result;
        toString(r->getRight());
    }
template <class T>
void BTree<T>::archivo(){
  std::ofstream archivoSalida("contactos.txt");  // Abre el archivo en modo de escritura

  if (archivoSalida.is_open()) {
    archivos(root, archivoSalida);  // Llama a la función auxiliar para escribir los datos en el archivo
    std::cout << "Datos del árbol guardados en el archivo exitosamente." << std::endl;
  } else {
    std::cout << "No se pudo abrir el archivo." << std::endl;
  }
  archivoSalida.close();
}
template <class T>
void BTree<T>::archivos(Position&r,std::ofstream& archivo){
if (r != nullptr) {
    archivo << r->getData().getName() << std::endl;
    archivo << r->getData().getNickname() << std::endl;
    archivo << r->getData().getTel() << std::endl;

    archivos (r->getLeft(), archivo);  // Llama recursivamente a archivo() para los nodos hijos izquierdos
    archivos (r->getRight(), archivo); // Llama recursivamente a archivo() para los nodos hijos derechos

}
}
template <class T>
void BTree<T>::recuperar(){
  std::ifstream archivoSalida("contactos.txt");  // Abre el archivo en modo de escritura

  if (archivoSalida.is_open()) {
    recupera(root, archivoSalida);  // Llama a la función auxiliar para escribir los datos en el archivo
    std::cout << "Datos del árbol guardados en el archivo exitosamente." << std::endl;
  } else {
    std::cout << "No se pudo abrir el archivo." << std::endl;
  }
  archivoSalida.close();
}
template <class T>
void BTree<T>::recupera(Position&r, std::ifstream& archivo){
   std::string nombre, nickname, telString;

    // Lee los datos del archivo línea por línea
    while (std::getline(archivo, nombre) &&
           std::getline(archivo, nickname) &&
           std::getline(archivo, telString)) {
        // Convierte el número de teléfono de tipo string a tipo long long int
        long long int tel = std::stoll(telString);

        // Crea un objeto de tipo Contacto
        Contacto contacto;

        // Establece los valores de los miembros de la clase utilizando los métodos de configuración
        contacto.setName(nombre);
        contacto.setNickname(nickname);
        contacto.setTel(tel);

        // Llama a insertData() pasando el objeto Contacto
        insertData(contacto);
    }
}




///--------------------------------------AVL-----------------------------------------
template <class T>
int BTree<T>::getBalance(Position& r) {
    if(r==nullptr or isLeaf(r)){
        return 0;
    }
    return getHeight(r->getRight())-getHeight(r->getLeft());

}
template <class T>
void BTree<T>::doleftrot(Position&r)
{
    Position aux1(r->getRight());
    Position aux2(aux1->getLeft());

    r->setRight(aux2);
    aux1->setLeft(r);
    r=aux1;

}
template <class T>
void BTree<T>::dorightrot(Position&r)
{
    Position aux1(r->getLeft());
    Position aux2(aux1->getRight());

    r->setLeft(aux2);
    aux1->setRight(r);
    r=aux1;

}
template <class T>
void BTree<T>::dobleleft(Position&r)
{
    dorightrot(r->getRight());
    doleftrot(r);
}
template <class T>
void BTree<T>::dobleright(Position&r)
{
    doleftrot(r->getLeft());
    dorightrot(r);
}

template <class T>
void BTree<T>::doBalancing(Position&r)
{
switch(getBalance(r)){
case -2:
    if(getBalance(r->getLeft())== -1)
    {

dorightrot(r);
    }else{
    dobleright(r);
    }
break;

case 2:
    if(getBalance(r->getRight())==1)
    {
        doleftrot(r);
    }else{
    dobleleft(r);
    }
    break;
}

}
template <class T>
typename BTree<T>::Position& BTree<T>::getIzq(){
    izq= root;
    izq = izq->getLeft();
    return izq;
}

template <class T>
typename BTree<T>::Position& BTree<T>::getDer(){
    der = root;
    der = der->getRight();
    return der;
}
///--------------------buscar--------------------

template<class T>
    typename BTree<T>::Position& BTree<T>::findData(const T& e){
    return findData(root,e);
    }

    template <class T>
    typename BTree<T>::Position& BTree<T>::findData(Position& r, const T& e){
    if(r == nullptr or r->getData()==e){
        return r;
    }
    if(e < r->getData()){
        return findData(r->getLeft(),e);
    }
    return findData(r->getRight(),e);

    }

 template<class T>
    void BTree<T>::retrieve(Position& r)const{
        if(r == nullptr){
        return;
}
        std::cout<<"CONTACTO ENCONTRADO: "<<r->getData().toString();


}



#endif // ARB_H_INCLUDED
