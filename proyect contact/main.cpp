#include <iostream>
#include<string>
#include<chrono>
#include<sys/time.h>
#include<ctime>
#include<fstream>
#include<ostream>
#include"ARB.hpp"
#include"contact.hpp"
#include"lista enlazada.hpp"


    CLista lista;
    BTree<Contacto>agenda;
    Contacto contacto;
    Llamadas llamadas;

std::string timeToString(std::chrono::system_clock::time_point &t)
{
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    std::string time_str = std::ctime(&time);
    time_str.resize(time_str.size() - 1);
    return time_str;
}
using namespace std;

int main()
{

    ifstream ar("contactos.txt");
    int menu,a;
    std:: string name;
    std:: string nickname;
    std:: string edicion;
    long long int tel;





    cout << "\t***BIENVENIDO A TU AGENDA TELEFONICA***" << endl<<endl;
   do{
    cout<<"SELECCIONE LA OPCION A EJECUTAR"<<endl;
    cout<<"[1]AGREGAR CONTACTO\n[2]EDITAR CONTACTO\n[3]ELIMINAR CONTACTO\n[4]BUSCAR CONTACTO\n[5]MOSTRAR LISTA DE CONTACTOS";
    cout<<"\n[6]GUARDAR CONTACTOS\n[7]CARGAR CONTACTOS\n[8]REALIZAR LLAMADA\n[9]MOSTRAR LLAMADAS\n[10]SALIR"<<endl<<endl;
    cin>>menu;
    system("cls");
    switch(menu){
    case 1:


        cin.ignore();
        cout<<"INGRESE EL NOMBRE"<<endl;
        getline(cin,name);
        contacto.setName(name);
        cout<<"INGRESE EL APODO"<<endl;
        getline(cin,nickname);

        contacto.setNickname(nickname);
        cout<<"INGRESE EL TELEFONO"<<endl;
        cin>>tel;

        contacto.setTel(tel);
        contacto.toString();
        agenda.insertData(contacto);



        cout<<"\t***AGREGADO CON EXITO***"<<endl;
        break;

    case 2:
        cin.ignore();
        cout<<"INGRESE EL CONTACTO A EDITAR: ";
        getline(cin,name);
        contacto.setName(name);
        contacto.toString();
        agenda.deleteData(agenda.findData(contacto));
        cout<<endl;
        cout<<"EDITANDO CONTACTO"<<endl;
        cout<<"INGRESE EL NUEVO TELEFONO"<<endl;
        cin>>tel;
        contacto.setTel(tel);
        cin.ignore();
        cout<<"INGRESE EL NUEVO APODO"<<endl;
        getline(cin,nickname);
        contacto.setNickname(nickname);
        cout<<"INGRESE EL  NUEVO NOMBRE"<<endl;
        getline(cin,name);
        contacto.setName(name);
        contacto.toString();
        agenda.insertData(contacto);
        cout<<"\t***CAMBIADO CON EXITO***"<<endl;

        break;
    case 3:
        cin.ignore();
        cout<<"INGRESE EL CONTACTO A ELIMINAR: ";
        getline(cin, name);
        contacto.setName(name);
        contacto.toString();

if (agenda.findData(contacto)) {
    agenda.deleteData(agenda.findData(contacto));
    cout << "ELIMINADO CON EXITO" << endl;
} else {
    cout << "EL CONTACTO NO EXISTE" << endl;
}
        break;
    case 4:
        do{
        cin.ignore();
        cout<<"INGRESE EL CONTACTO A BUSCAR: ";
        getline(cin,name);
        contacto.setName(name);

        agenda.retrieve(agenda.findData(contacto));

        cout<<endl;
        cout<<"DESEA BUSCAR OTRO?\n[1]SI\n[2]NO"<<endl;
        cin>>a;
        }while(a!=2);
        break;
    case 5:
        agenda.toString();
        break;
    case 6:
        agenda.archivo();
        break;
    case 7:
    agenda.recuperar();



        break;
    case 9:
        lista.Recuperar();
        lista.Imprime();
        break;
    case 8:

        auto time_p = std::chrono::system_clock::now();
        Llamadas * llamadas =new Llamadas;
        cin.ignore();
        cout<<"AQUIEN DESEA LLAMAR: ";
        getline(cin,name);
        contacto.setName(name);
        agenda.retrieve(agenda.findData(contacto));
        llamadas->setTime(timeToString(time_p));
        llamadas->setEstado("ocupado");

        lista.insertarInicio(llamadas);
        lista.Imprime();
        lista.Guardar();
        break;




    }

}while(menu!=10);
return 0;
}

