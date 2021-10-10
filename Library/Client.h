//
// Created by bogdan on 04.05.2021.
//

#ifndef BIBLIOTECA_CLIENT_H
#define BIBLIOTECA_CLIENT_H
#include<iostream>
#include<string>
#include<vector>

using namespace  std;

class Client {
private:
    string m_numeClient;
    int  m_nrOperatii;
    vector<int> m_tipOpertii;
public:
    Client();
    Client(string numeClient, int nrOperatii, vector<int>& tipOperatii);
};


#endif //BIBLIOTECA_CLIENT_H
