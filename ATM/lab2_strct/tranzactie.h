#ifndef TRANZACTIE_H
#define TRANZACTIE_H
#include "collection.h"
#include <string.h>
#include <iostream>

typedef int TElem;

class Tranzactie
{
private:
	Collection bancnote;
	int idTranzactie;
	int suma;

public:
	Tranzactie();
	~Tranzactie();

	void add(int id, int suma, int bani[], int n);
	void citire(int suma, int nr);
	void afis();
	void backtrack(int k, int sp);
	void metodaselect();
	void afisvar2();

	int size();
	int getel(int poz);
	int send();
	int getvect(int poz);

	int getsuma();
	int getid();

	std::string tostring();
};

#endif