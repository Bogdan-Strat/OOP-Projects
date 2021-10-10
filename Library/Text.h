//
// Created by bogdan on 29.04.2021.
//

#ifndef BIBLIOTECA_TEXT_H
#define BIBLIOTECA_TEXT_H

#include <ostream>
#include "Informatii.h"

using  namespace std;

class Text: public Informatii {
private:
    string m_Text;
    map<int, Text> m_mapIdText;
    map<string , Text> m_mapAliasText;
public:
    Text();
    Text(string Text);
    //Text(string Alias,string Text);

    const map<int, Text> &getMapIdText() const;
    const map<string, Text> &getMapAliasText() const;

    friend ostream &operator<<(ostream &os, const Text &text);
    Text operator+(Text const &obj);
    bool operator==(const Text &rhs) const;

    void adaugareInformatiiText(string text, string Alias="");

    void stergereInformatiiId(int Id) override;
    void stergereInformatiiAlias(string Alias) override;

    bool regasireInformatiiId(int Id) override;
    bool regasireInformatiiAlias(string Alias) override;

    bool cautareInformatiiText(const Text& Text);

};


#endif //BIBLIOTECA_TEXT_H
