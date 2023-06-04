#include"contact.hpp"

using namespace std;

Contacto::Contacto() {}

Contacto::Contacto(const Contacto& a):name(a.name),nickname(a.nickname),tel(a.tel){}

Contacto& Contacto::operator = (const Contacto& a) {

    name=a.name;
    nickname=a.nickname;
    tel=a.tel;
    return *this;
    }

 long long int Contacto::getTel() const {
    return tel;

    }
string Contacto::getName() const
{
    return name;
}
string Contacto::getNickname() const
{
    return nickname;
}

string Contacto::toString() const {
    string result;

    result = name;
    result.resize(15,' ');
    result += "|";

    result += nickname;
    result.resize(25,' ');
    result += "|";

    result += to_string(tel);
    result.resize(37,' ');

    return result;


    }

void Contacto::setTel(const long long int &t) {
    tel = t;

    }

void Contacto::setName(const std::string& n)
{
    name = n;
}

void Contacto::setNickname(const std::string& a)
{
    nickname = a;
}



    bool Contacto::operator == (const Contacto& n) const
{
    return name == n.name;
}

bool Contacto::operator != (const Contacto& n) const
{
    return name != n.name;
}

bool Contacto::operator < (const Contacto& n) const
{
    return name < n.name;
}

bool Contacto::operator<=(const Contacto& n) const
{
    return name <= n.name;
}

bool Contacto::operator>(const Contacto& n) const
{
    return name > n.name;
}

bool Contacto::operator>=(const Contacto& n) const
{
    return name >= n.name;
}

