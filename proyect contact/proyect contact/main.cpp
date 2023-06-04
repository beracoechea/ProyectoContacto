#include <iostream>
#include<string>
#include"ARB.hpp"
#include"contact.hpp"

using namespace std;

int main()
{
    string nombre;
    string apodo;
    string busqueda;
    long long int telefono;
    Contacto cont;
    int menu,modificacion;

    cout << "\t***BIENVENIDO A TU AGENDA TELEFONICA***" << endl<<endl;
    BTree<Contacto>agenda;

   do{
    cout<<"SELECCIONE LA OPCION A EJECUTAR"<<endl;cout<<"[1]AGREGAR CONTACTO\n[2]EDITAR CONTACTO\n[3]ELIMINAR CONTACTO\n[4]BUSCAR CONTACTO\n[5]MOSTRAR LISTA DE CONTACTOS\n[6]LISTA DE LLAMADAS\n[7]SALIR"<<endl<<endl;
    cin>>menu;
    system("cls");
    switch(menu){

case 1:
    cout<<"SELECCIONO AGREGAR CONTACTO"<<endl<<endl;
    cin.ignore();
    cout<<"NAME:";
    getline(cin,nombre);
    cont.setName(nombre);

    cout<<"NICKNAME:";
    getline(cin,apodo);
    cont.setNickname(apodo);

    cout<<"NO.TELEFONICO:";
    cin>>telefono;
    cont.setTel(telefono);

    agenda.insertData(cont);
    cout<<endl<<endl;

    break;
case 2:
    cout<<"SELECCIONO EDITAR CONTACTO"<<endl<<endl;
    cout<<"INGRESE EL NOMBRE DEL CONTACTO:\t";
    cin>>nombre;
    cont.setName(nombre);
    agenda.retrieve(agenda.findData(cont));
    cout<<"QUE DESEA MODIFICAR?\n[1]NOMBRE\n[2]APODO\n[3]TELEFONO"<<endl<<endl;
    cin>>modificacion;
   cout<<endl;
    if(modificacion==1){
            cin.ignore();
        cout<<"INGRESE LA NUEVA INFORMACION:\t";
       getline(cin,nombre);
        cont.setName(nombre);
    }else if(modificacion==2){
        cin.ignore();
        cout<<"INGRESE LA NUEVA INFORMACION:\t";
        getline(cin,apodo);
         cont.setNickname(apodo);
    }else if(modificacion==3){
        cin.ignore();
        cout<<"INGRESE LA NUEVA INFORMACION:\t";
        cin>>telefono;
         cont.setTel(telefono);
    }

    break;
case 3:
    cout<<"SELECCIONO ELIMINAR CONTACTO"<<endl<<endl;
     cout<<"INGRESE EL NOMBRE DEL CONTACTO:\t";
    cin>>nombre;
    cont.setName(nombre);
   cout<<endl;
     agenda.deleteData(agenda.findData(cont));
    cout<<endl;
    break;
case 4:
    cout<<"SELECCIONO BUSCAR CONTACTO"<<endl<<endl;
    cout<<"INGRESE EL NOMBRE DEL CONTACTO:\t";
    cin>>nombre;
    cont.setName(nombre);cout<<endl;
    cout<<agenda.retrieve(agenda.findData(cont)).toString()<<endl<<endl;
    break;
case 5:
    cout<<endl<<endl;
    cout<<"\t***LISTA DE CONTACTOS***"<<endl<<endl;
    agenda.toString();
    cout<<endl<<endl;
    break;
case 6:
    break;
    }

    }while(menu!=7);

    return 0;
}
