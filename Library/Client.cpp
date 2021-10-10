//
// Created by bogdan on 04.05.2021.
//

#include "Client.h"

Client::Client() {

}

Client::Client(string numeClient, int nrOperatii, vector<int> &tipOperatii) {
    m_numeClient=numeClient;
    m_nrOperatii=nrOperatii;
    m_tipOpertii=tipOperatii;
}
