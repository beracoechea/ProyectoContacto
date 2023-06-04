#ifndef CONTACT_H_INCLUED
#define CONTACT_H_INCLUED

#include<iostream>
#include<string>
class Contacto{
private:
   std:: string name;
   std:: string nickname;
   long long int tel;


public:
     Contacto();
     Contacto(const Contacto&);

       long long int getTel() const;
        std::string getName()const;
        std::string getNickname()const;

        std::string toString()const;

        void setTel(const long long int&);
        void setName(const std::string&);
        void setNickname(const std::string&);

        Contacto & operator =(const Contacto&);

        bool operator == (const Contacto&) const;
        bool operator != (const Contacto&) const;
        bool operator < (const Contacto&) const;
        bool operator <= (const Contacto&) const;
        bool operator > (const Contacto&) const;
        bool operator >= (const Contacto&) const;


};

#endif // CONTACT_H_INCLUED
