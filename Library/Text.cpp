//
// Created by bogdan on 29.04.2021.
//

#include "Text.h"

Text::Text() {

}

Text::Text( string Text){
    m_Text=Text;
}

const map<int, Text> &Text::getMapIdText() const {
    return m_mapIdText;
}

const map<string, Text> &Text::getMapAliasText() const {
    return m_mapAliasText;
}

ostream &operator<<(ostream &os, const Text &text) {
    os << " Textul: " << text.m_Text;
    return os;
}

Text Text::operator+(const Text &obj) {
    Text Rezultat;
    Rezultat.m_Text=m_Text+obj.m_Text;
    return  Rezultat;
}

bool Text::operator==(const Text &rhs) const {
    return m_Text == rhs.m_Text;
}

void Text::adaugareInformatiiText(string text, string Alias) {
    Informatii i;
    Text Mesaj(text);
    int a=i.getId();
    int ok=0;
    if(Alias!=""){
        for(auto x: m_mapAliasText){
            if(x.first==Alias){
                ok=1;
                break;
            }

        }
        if(ok==1){
            m_mapAliasText[Alias]=m_mapAliasText[Alias]+Mesaj;
        }
        else{
            m_mapAliasText[Alias]=Mesaj;
        }
    }
    if(ok==0)
        m_mapIdText[a]=Mesaj;

}

void Text::stergereInformatiiId(int Id) {
    for(auto x: m_mapIdText){
        if(x.first==Id){
            m_mapIdText.erase(x.first);
            break;
        }
    }
}

void Text::stergereInformatiiAlias(string Alias) {
    map<string, Text> mp;
    for(auto x:m_mapAliasText){
        if(x.first!=Alias){
            mp[x.first]=m_mapAliasText[x.first];
        }
    }
    m_mapAliasText=mp;
}

bool Text::regasireInformatiiId(int Id) {
    for(auto x: m_mapIdText){
        if(x.first==Id)
            return true;
    }
    return false;
}

bool Text::regasireInformatiiAlias(string Alias) {
    for(auto x: m_mapAliasText){
        if(x.first==Alias)
            return true;
    }
    return false;
}

bool Text::cautareInformatiiText(const Text &Text) {
    for(auto x: m_mapIdText){
        if(x.second==Text){
            return true;
        }
    }
    return false;
}

//Text::Text(string Alias, string Text): Informatii( Alias) {
//    m_Text=Text;
//}




