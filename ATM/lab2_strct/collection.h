#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include "List.h"
#include "vector_dinamic.h"
using namespace std;

typedef int TElem;

struct Element
{    
    TElem valoare;
    int nr_aparitii;
};

class Collection 
{
private:
    List<Element> elements;      
    int distinctelements;   // numarul de elemente distincte
    int capacity; 
    void resize();

public:
    Collection();               //constructor fara parametrii
    void Destructor();          //destructor

    void add(TElem elem);       //adaugare de noi obiecte in colectie
    bool remove(TElem elem);    //sterge un element din colectie

    bool search(TElem elem);    //cauta un element in clasa
    int size();                 //returneaza dimensiunea
    int nroccurrences(TElem elem);              //returneaza numarul de aparitii a unui obiect dat
    int getAt(int position);                    //returneaza numarul de aparitii ale unui obiect de pe pozitia data
    int get_lungime();                          //returneaza numarul de elemente distincte din sir
    TElem get_val(int position);                //returneaza obiectul aflat pe pozitia data

};

#endif 
