#include <iostream>
#include <fstream>
#include<map>
#include<vector>

#include "Informatii.h"
#include "Text.h"
#include "Numeric.h"
#include "Matematic.h"
#include "Adresa.h"
#include "Biblioteca.h"
#include "Client.h"

using namespace std;

class Informatii;
class Matematic;
ifstream f("date.in");
int main() {
    int i,nrClienti;
    map<int,Matematic> mapIdMatematic;
    map<string,Matematic> mapAliasMatematic;
    map<int, Numeric> mapIdNumeric;
    map<string, Numeric> mapAliasNumeric;
    map<int, Text> mapIdText;
    map<string, Text> mapAliasText;
    map<int, Adresa> mapIdAdresa;
    map<string, Adresa> mapAliasAdresa;

    Matematic numarComplex;
    Numeric Numar;
    Text Mesaj;
    Adresa Adress;
    Client client;

    int nrDateBD,nrDateMatematice, nrDateNumerice, nrDateText, nrDateAdresa,val;
    float parteaReala, parteaImaginara;
    unsigned int numarNatural;
    string Txt, Tara, Oras, Judet, Strada, numeBiblioteca, numeDirector,Alias,numeClient;
    int numarStrada,nrOperatii;
    vector<int> tipOperatii;

    cout<<"Introdu numele Bibliotecii: ";
    cin>>numeBiblioteca;
    cout<<"Introdu numee tau: ";
    cin>>numeDirector;
    Biblioteca Biblioteca(numeBiblioteca, numeDirector);
    cout<<"Bine ai revenit "<<numeDirector<<" la Biblioteca "<<numeBiblioteca;
    cout<<"!\nSarcina ta pe azi este sa reintroduci datele din vechea baza de date in cea nou!!! Pentru asta te rog completeaza urmatoarele campuri:\n";
    cout<<"Numarul datelor ce trebuiesc introduse: ";
    cin>>nrDateBD;
    cout<<"Numarul datelor de tip Adresa: ";
    cin>>nrDateAdresa;
    cout<<"Numarul datelor de tip Text: ";
    cin>>nrDateText;
    cout<<"Numarul datelor de tip Numeric: ";
    cin>>nrDateNumerice;
    cout<<"Numarul datelor de tip Matematic: ";
    cin>>nrDateMatematice;

    if(nrDateNumerice+nrDateMatematice+nrDateAdresa+nrDateText!=nrDateBD){
        cout<<"Numarul datelor pe care vrei sa le introducieste eronat!\nTe rugam sa o iei de la inceput!";
        return 0;
    }

    cout<<"Urmatorul pas este sa introduci datele din vechea baza de date:\n";
    cout<<"Introdu datele de tip Adresa:\n";
    for(i=0;i<nrDateAdresa;++i){
        cout<<i+1<<"). Tara: ";
        cin>>Tara;
        cout<<"Judetul: ";
        cin>>Judet;
        cout<<"Orasul: ";
        cin>>Oras;
        cout<<"Strada: ";
        cin>>Strada;
        cout<<"Numarul strazii: ";
        cin>>numarStrada;
        cout<<"Bifeaza 1 daca informatia oferita are vreun alias si 0 in caz contrar: ";
        cin>>val;
        if(val==0)
            Adress.adaugareInformatiiAdresa(Tara,Judet, Oras, Strada, numarStrada);
        else{
            cout<<"Noteaza Aliasul: ";
            cin>>Alias;
            Adress.adaugareInformatiiAdresa(Tara,Judet, Oras, Strada, numarStrada,Alias);

        }

    }

    cout<<"Acum introdu datele de tip Text:\n";
    for(i=0;i<nrDateText;++i){
        cout<<i+1<<"). Mesaj: ";
        cin>>Txt;
        cout<<"Bifeaza 1 daca informatia oferita are vreun alias si 0 in caz contrar: ";
        cin>>val;
        if(val==0)
            Mesaj.adaugareInformatiiText(Txt);
        else{
            cout<<"Noteaza Aliasul: ";
            cin>>Alias;
            Mesaj.adaugareInformatiiText(Txt, Alias);
        }

    }

    cout<<"Acum introdu datele de tip Numeric:\n";
    for(i=0;i<nrDateNumerice;++i){
        cout<<i+1<<").  Numarul natural: ";
        cin>>numarNatural;
        cout<<"Bifeaza 1 daca informatia oferita are vreun alias si 0 in caz contrar: ";
        cin>>val;
        if(val==0)
            Numar.adaugareInformatiiNumerice(numarNatural);
        else{
            cout<<"Noteaza Aliasul: ";
            cin>>Alias;
            Numar.adaugareInformatiiNumerice(numarNatural, Alias);
        }
    }

    cout<<"Acum intordu datele de tip Matematic:\n";
    for(i=0;i<nrDateMatematice;++i){
        cout<<i+1<<"). Partea reala: ";
        cin>>parteaReala;
        cout<<"Partea imaginara: ";
        cin>>parteaImaginara;
        cout<<"Bifeaza 1 daca informatia oferita are vreun alias si 0 in caz contrar: ";
        cin>>val;
        if(val==0)
            numarComplex.adaugareInformatiiMatematice(parteaReala, parteaImaginara);
        else{
            cout<<"Noteaza Aliasul: ";
            cin>>Alias;
            numarComplex.adaugareInformatiiMatematice(parteaReala, parteaImaginara, Alias);
        }
    }

    int j,countAdaugare=0, countStergere=0, countRegasire=0, countCautare=0,tip,a,Id;

    cout<<"Acum esti pregatit sa incepi prima ta zi de munca! Spor!\n";
    cout<<"Introdu numarul clientilor de astazi: ";
    cin>>nrClienti;
    for(i=0;i<nrClienti;++i){
        cout<<"Nume client: ";
        cin>>numeClient;
        cout<<"Numarul de operatii ce le vrea efectuate: ";
        cin>>nrOperatii;
        cout<<"Acum introdu tipul fiecarei operatii pe rand:\n"
              "1. Pentru adaugarea de informatii noi\n"
              "2. Pentru stergerea unor informatii\n"
              "3. Pentru regasirea unor informatii\n"
              "4.Pentru cautarea unor informatii\n";
        for(j=0;j<nrOperatii;++j){
            cin>>val;
            if(val==1){
                cout<<"Acum introdu tipul informatiei pe care vrei sa o adaugi:\n"
                      "1. Pentru tipul Adresa\n"
                      "2. Pentru tipul Text\n"
                      "3. Pentru tipul Numeric\n"
                      "4. Pentru tipul Matematic";
                cin>>tip;
                if(tip==1){
                    cout<<"Introdu:\n"
                          "Tara: ";
                    cin>>Tara;
                    cout<<"Judetul: ";
                    cin>>Judet;
                    cout<<"Orasul: ";
                    cin>>Oras;
                    cout<<"Strada: ";
                    cin>>Strada;
                    cout<<"Numarul strazii: ";
                    cin>>numarStrada;
                    cout<<"Daca vrei sa dai un alias informatiei tale tasteaza 1, in caz contrat 0: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Alias: ";
                        cin>>Alias;
                        Adress.adaugareInformatiiAdresa(Tara,Judet,Oras,Strada, numarStrada,Alias);
                    }
                    else
                        Adress.adaugareInformatiiAdresa(Tara,Judet,Oras,Strada, numarStrada);

                    countAdaugare++;

                }
                else if(tip==2){
                    cout<<"Introdu mesajul: ";
                    cin>>Txt;
                    cout<<"Daca vrei sa dai un alias informatiei tale tasteaza 1, in caz contrat 0: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Alias: ";
                        cin>>Alias;
                        Mesaj.adaugareInformatiiText(Txt,Alias);
                    }
                    else
                        Mesaj.adaugareInformatiiText(Txt);
                    ++countAdaugare;
                }
                else if(tip==3){
                    cout<<"Introdu numarul natural: ";
                    cin>>numarNatural;
                    cout<<"Daca vrei sa dai un alias informatiei tale tasteaza 1, in caz contrat 0: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Alias: ";
                        cin>>Alias;
                        Numar.adaugareInformatiiNumerice(numarNatural,Alias);
                    }
                    else
                        Numar.adaugareInformatiiNumerice(numarNatural);
                    ++countAdaugare;
                }
                else {
                    cout << "Introdu:\n"
                            "Partea reala: ";
                    cin >> parteaReala;
                    cout << "Partea imaginara: ";
                    cin >> parteaImaginara;

                    cout << "Daca vrei sa dai un alias informatiei tale tasteaza 1, in caz contrat 0: ";
                    cin >> a;
                    if (a == 1) {
                        cout << "Alias: ";
                        cin >> Alias;
                        numarComplex.adaugareInformatiiMatematice(parteaReala, parteaImaginara, Alias);
                    } else
                        numarComplex.adaugareInformatiiMatematice(parteaReala, parteaImaginara);
                    ++countAdaugare;
                }
            }
            else if(val==2){

                cout<<"Acum introdu tipul informatiei pe care vrei sa o adaugi:\n"
                      "1. Pentru tipul Adresa\n"
                      "2. Pentru tipul Text\n"
                      "3. Pentru tipul Numeric\n"
                      "4. Pentru tipul Matematic";
                cin>>tip;
                if(tip==1){
                    cout<<"Introdu 1 daca stergerea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        Adress.stergereInformatiiId(Id);

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        Adress.stergereInformatiiAlias(Alias);
                    }
                    ++countStergere;
                }
                else if(tip==2){
                    cout<<"Introdu 1 daca stergerea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        Mesaj.stergereInformatiiId(Id);

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        Mesaj.stergereInformatiiAlias(Alias);
                    }
                    ++countStergere;
                }
                else if(tip==3){
                    cout<<"Introdu 1 daca stergerea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        Numar.stergereInformatiiId(Id);

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        Numar.stergereInformatiiAlias(Alias);
                    }
                    ++countStergere;
                }
                else{
                    cout<<"Introdu 1 daca stergerea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        numarComplex.stergereInformatiiId(Id);

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        numarComplex.stergereInformatiiAlias(Alias);
                    }
                    ++countStergere;
                }

            }
            else if(val==3){
                cout<<"Acum introdu tipul informatiei pe care vrei sa o regasesti:\n"
                      "1. Pentru tipul Adresa\n"
                      "2. Pentru tipul Text\n"
                      "3. Pentru tipul Numeric\n"
                      "4. Pentru tipul Matematic";
                cin>>tip;
                if(tip==1){
                    cout<<"Introdu 1 daca regasirea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        cout<<"Rezultat: "<<Adress.regasireInformatiiId(Id)<<'\n';

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        cout<<"Rezultat: "<<Adress.regasireInformatiiAlias(Alias)<<'\n';
                    }
                    ++countRegasire;
                }
                else if(tip==2){
                    cout<<"Introdu 1 daca regasirea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        cout<<"Rezultat: "<<Mesaj.regasireInformatiiId(Id)<<'\n';

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        cout<<"Rezultat: "<<Mesaj.regasireInformatiiAlias(Alias)<<'\n';
                }
                    ++countRegasire;
            }
                else if(tip==3){
                    cout<<"Introdu 1 daca regasirea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        cout<<"Rezultat: "<<Numar.regasireInformatiiId(Id)<<'\n';

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        cout<<"Rezultat: "<<Numar.regasireInformatiiAlias(Alias)<<'\n';
                    }
                    ++countRegasire;
                }
                else{
                    cout<<"Introdu 1 daca regasirea se va face dupa ID sau 0 daca va fi dupa Alias: ";
                    cin>>a;
                    if(a==1){
                        cout<<"Introdu Id-ul: ";
                        cin>>Id;
                        cout<<"Rezultat: "<<numarComplex.regasireInformatiiId(Id)<<'\n';

                    }
                    else{
                        cout<<"Introdu Aliasul: ";
                        cin>>Alias;
                        cout<<"Rezultat: "<<numarComplex.regasireInformatiiAlias(Alias)<<'\n';
                    }
                    ++countRegasire;
                }
            }
            else if(val==4){
                cout<<"Acum introdu tipul informatiei pe care vrei sa o cauti:\n"
                      "1. Pentru tipul Adresa\n"
                      "2. Pentru tipul Text\n"
                      "3. Pentru tipul Numeric\n"
                      "4. Pentru tipul Matematic";
                cin>>tip;
                if(tip==1){
                    cout<<"Introdu:\n"
                          "Tara: ";
                    cin>>Tara;
                    cout<<"Judetul: ";
                    cin>>Judet;
                    cout<<"Orasul: ";
                    cin>>Oras;
                    cout<<"Strada: ";
                    cin>>Strada;
                    cout<<"Numarul strazii: ";
                    cin>>numarStrada;
                    Adresa Adr(Tara,Judet,Oras,Strada,numarStrada);
                    cout<<"Rezultat: "<<Adress.cautareInformatiiAdresa(Adr)<<'\n';
                    ++countCautare;
                }
                else if(tip==2){
                    cout<<"Introdu:\nMesajul: ";
                    cin>>Txt;
                    Text Msj(Txt);
                    cout<<"Rezultat: "<<Mesaj.cautareInformatiiText(Msj)<<'\n';
                    ++countCautare;
                }
                else if(tip==3){
                    cout<<"Introdu:\nNumarul natural: ";
                    cin>>numarNatural;
                    Numeric nr(numarNatural);
                    cout<<"Rezultat: "<<Numar.cautareInformatiiNumerice(nr);
                    ++countCautare;
                }
                else{
                    cout<<"Introdu:\nPartea reala: ";
                    cin>>parteaReala;
                    cout<<"Partea imaginara: ";
                    cin>>parteaImaginara;
                    Matematic Complex(parteaReala, parteaImaginara);
                    cout<<"Rezultat: "<<numarComplex.cautareInformatiiMatematice(Complex)<<'\n';
                    ++countCautare;
                }
            }
        }

    }
    cout<<"Felicitari! Prima ta zi de munca s-a incheiat! Astazi s-au produs urmatoarele modificari in cadrul bazei noastre de date:\n";
    cout<<"Numarul de informatii noi adaugate: "<<countAdaugare<<'\n';
    cout<<"Numarul de informatii sterse: "<<countStergere<<'\n';
    cout<<"Numarul de operatii de regasire: "<<countRegasire<<'\n';
    cout<<"Numarul de operatii de cautare: "<<countCautare<<'\n';
    cout<<"Numarul total de operatii este: "<<countCautare+countRegasire+countStergere+countAdaugare;



//    Adresa adr;
//    if(adr.adaugareInformatiiAdresa("ro","gl","gl","tser",45,"acasa")==false)
//        cout<<"Eroare";
//    if(adr.adaugareInformatiiAdresa("ger","ber","ber","polizei",3)==false)
//        cout<<"Eroare";
//    if(adr.adaugareInformatiiAdresa("ro","gl","gl","cosbuc",254,"birou")==false)
//        cout<<"Eroare";
//    if(adr.adaugareInformatiiAdresa("fr","arondisment","paris","seru",8)==false)
//        cout<<"Eroare";
//    if(adr.adaugareInformatiiAdresa("eng","district","lon","queen",5,"birou")==false)
//        cout<<"Eroare";
//
//    cout<<"Afisare initiala:\n";
//
//    mapIdAdresa=adr.getMapIdAdresa();
//    mapAliasAdresa=adr.getMapAliasAdresa();
//
//    for(auto x: mapIdAdresa){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAliasAdresa){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    adr.stergereInformatiiId(7);
//    adr.stergereInformatiiAlias("acasa");
//
//    mapIdAdresa=adr.getMapIdAdresa();
//    mapAliasAdresa=adr.getMapAliasAdresa();
//
//    cout<<"Afisare finala:\n";
//    for(auto x: mapIdAdresa){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAliasAdresa){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    Text txt;
//    txt.adaugareInformatiiText("nume","poo");
//    txt.adaugareInformatiiText("man");
//    txt.adaugareInformatiiText("mangusta","gtr");
//    txt.adaugareInformatiiText("u");
//    txt.adaugareInformatiiText(" picanta","gtr");
//
//    cout<<"Afisare initiala:\n";
//
//    mapIdText=txt.getMapIdText();
//    mapAliasText=txt.getMapAliasText();
//
//    for(auto x: mapIdText){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAliasText){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    txt.stergereInformatiiId(6);
//    txt.stergereInformatiiAlias("poo");
//
//    mapIdText=txt.getMapIdText();
//    mapAliasText=txt.getMapAliasText();
//
//    cout<<"Afisare finala:\n";
//    for(auto x: mapIdText){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAliasText){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    cout<<"Numeric: \n";
//
//    Numeric numar;
//    numar.adaugareInformatiiNumerice(5);
//    numar.adaugareInformatiiNumerice(3,"fav");
//    numar.adaugareInformatiiNumerice(7,"pal");
//    numar.adaugareInformatiiNumerice(17);
//    numar.adaugareInformatiiNumerice(7,"fav");
//    numar.adaugareInformatiiNumerice(2);
//
//    cout<<"Afisare initiala:\n";
//
//    mapIdNumeric=numar.getMMapId();
//    mapAliasNumeric=numar.getMMapAlias();
//
//    for(auto x: mapIdNumeric){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAliasNumeric){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    numar.stergereInformatiiId(25);
//    numar.stergereInformatiiAlias("pal");
//
//    mapIdNumeric=numar.getMMapId();
//    mapAliasNumeric=numar.getMMapAlias();
//
//    cout<<"Afisare finala:\n";
//    for(auto x: mapIdNumeric){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAliasNumeric){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    cout<<"Cautare informatii:\n";
//    cout<<numar.regasireInformatiiId(36)<<'\n';
//    cout<<numar.regasireInformatiiId(25)<<'\n';
//    cout<<numar.regasireInformatiiAlias("pal")<<'\n';
//    cout<<numar.regasireInformatiiAlias("fav")<<'\n';
//
//    cout<<"Regasire informatii:\n";
//    Numeric  nr(5),nr1(89),nr2(2),nr3(12);
//    cout<<numar.cautareInformatiiNumerice(nr)<<'\n';
//    cout<<numar.cautareInformatiiNumerice(nr1)<<'\n';
//    cout<<numar.cautareInformatiiNumerice(nr2)<<'\n';
//    cout<<numar.cautareInformatiiNumerice(nr3)<<'\n';


//    Matematic mate;
//    mate.adaugareInformatiiMatematice(12,15);
//    mate.adaugareInformatiiMatematice(2,0);
//    mate.adaugareInformatiiMatematice(0,8,"ltg");
//    mate.adaugareInformatiiMatematice(3,5,"lat");
//    mate.adaugareInformatiiMatematice(12,15,"ltg");
//
//    mapId=mate.getMMapId();
//    mapAlias=mate.getMMapAlias();
//
//    cout<<"Matematic:\n";
//    cout<<"Afisare initiala:\n";
//    for(auto x: mapId){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAlias){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    mate.stergereInformatiiId(2);
//    mate.stergereInformatiiAlias("ltg");
//
//    mapId=mate.getMMapId();
//    mapAlias=mate.getMMapAlias();
//
//    cout<<"Afisare finala:\n";
//    for(auto x: mapId){
//        cout<<"Index: "<<x.first<<" "<<x.second<<'\n';
//    }
//    for(auto x: mapAlias){
//        cout<<"Alias: "<<x.first<<" "<<x.second<<'\n';
//    }
//
//    cout<<"Cautare inforatii:\n";
//    cout<<mate.regasireInformatiiId(8)<<'\n';
//    cout<<mate.regasireInformatiiId(2)<<'\n';
//    cout<<mate.regasireInformatiiAlias("ltg")<<'\n';
//    cout<<mate.regasireInformatiiAlias("lat")<<'\n';
//
//    cout<<"Regasire informatii:\n";
//    Matematic  m(1,2),m1(3,5),m2(12,15),m3(12,23);
//    cout<<mate.cautareInformatiiMatematice(m)<<'\n';
//    cout<<mate.cautareInformatiiMatematice(m1)<<'\n';
//    cout<<mate.cautareInformatiiMatematice(m2)<<'\n';
//    cout<<mate.cautareInformatiiMatematice(m3)<<'\n';
    return 0;
}
