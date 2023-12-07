#ifndef ATM_H
#define ATM_H
#include "collection.h"
#include "tranzactie.h"
#include <iostream>
#include <fstream>
#include <string>

class Atm
{
private:
    Tranzactie* tranz;
    Collection bancnote;
    int nrtranz;

public:
    Atm();
    ~Atm();

    int randomid();
    void loadbanifromfile();
    void writetranztofile();
    void writebanitofile();
    void addBancnota(int bill, int size);
    void showFunds();
    void addTranz();
    void showTranz();
};
#endif