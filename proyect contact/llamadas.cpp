#include"Llamadas.hpp"
using namespace std;

Llamadas::Llamadas() {}

Llamadas::Llamadas(const Llamadas& a):tel(a.tel),time(a.time),estado(a.estado){}

Llamadas& Llamadas::operator = (const Llamadas& a) {

    tel=a.tel;
    time=a.time;
    estado=a.estado;

    return *this;
    }

 long long int Llamadas::getTel() const {
    return tel;

    }
string Llamadas::getTime() const
{
    return time;
}
string Llamadas::getEstado()const{
return estado;
}


string Llamadas::toString() const {
    string result;



    result += "FECHA: ";

    result += time;
    result.resize(39,' ');
    result += "hrs";

    result += "|";
    result +=estado;


    return result;


    }

void Llamadas::setTel(const long long int &t) {
    tel = t;

    }

void Llamadas::setTime(const string& n)
{
    time = n;
}
void Llamadas::setEstado(const string& e){
estado= e;
}


    bool Llamadas::operator == (const Llamadas& n) const
{
    return tel == n.tel;
}

bool Llamadas::operator != (const Llamadas& n) const
{
    return tel != n.tel;
}

bool Llamadas::operator < (const Llamadas& n) const
{
    return tel < n.tel;
}

bool Llamadas::operator<=(const Llamadas& n) const
{
    return tel <= n.tel;
}

bool Llamadas::operator>(const Llamadas& n) const
{
    return tel > n.tel;
}

bool Llamadas::operator>=(const Llamadas& n) const
{
    return tel >= n.tel;
}

