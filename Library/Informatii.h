//
// Created by bogdan on 29.04.2021.
//

#ifndef BIBLIOTECA_INFORMATII_H
#define BIBLIOTECA_INFORMATII_H

#include<iostream>
#include<string>
#include<map>

using namespace  std;

class Informatii {
private:
protected:
    int m_Id;
    static int m_nextId;
    string m_Alias;
public:
    Informatii();
    //Informatii(int Id);
    Informatii(string Alias);

    /*Informatii(const Informatii& orig);
    Informatii& operator=(const Informatii& orig);*/

    int getId() const;
    string getAlias() const;

    int setId(int Id);
    string setAlias(string Alias);

    virtual void adaugareInformatiiMatematice(float Real, float Imaginar, string Alias="");
    /*virtual void adaugareInformatiiText( float Real, float Imaginar, int Id, string Alias="");*/
    virtual void adaugareInformatiiNumerice( unsigned int Numar, string Alias="");
    /*virtual void adaugareInformatiiAdresa( float Real, float Imaginar, int Id, string Alias="");*/

    virtual void stergereInformatiiId(int Id);
    virtual void stergereInformatiiAlias(string Alias);

    virtual bool regasireInformatiiId(int Id);
    virtual bool regasireInformatiiAlias(string Alias);

     /*virtual void cautareInformatii(int Id, string Alias="");*/


};


#endif //BIBLIOTECA_INFORMATII_H
