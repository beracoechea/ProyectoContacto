#ifndef LLAMADAS_H_INCLUED
#define LLAMADAS_H_INCLUED

#include<iostream>
#include<string>
class Llamadas
    {
private:
    long long int tel;
   std:: string time;
   std::string estado;

public:
      Llamadas();
      Llamadas(const Llamadas&);

        virtual long long int getTel() const;
        virtual  std::string getTime()const;
        virtual  std::string getEstado()const;

        virtual std::string toString()const;

        virtual void setTel(const long long int&);
        virtual void setTime(const std::string&);
        virtual void setEstado(const std::string&);


       virtual Llamadas & operator =(const Llamadas&);

       virtual bool operator == (const Llamadas&) const;
      virtual  bool operator != (const Llamadas&) const;
      virtual  bool operator < (const Llamadas&) const;
      virtual  bool operator <= (const Llamadas&) const;
      virtual  bool operator > (const Llamadas&) const;
      virtual  bool operator >= (const Llamadas&) const;


};

#endif // LLAMADAS_H_INCLUED
