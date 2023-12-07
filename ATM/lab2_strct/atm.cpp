#pragma warning(disable: 4996)
#include "atm.h"
#include "tranzactie.h"
#include <fstream>
#include <iostream>
#include<cstdlib>

using namespace std;

Atm::Atm()
{
	tranz = new Tranzactie[10];
	nrtranz = 0;
	loadbanifromfile();
}

Atm::~Atm() 
{
	delete[] tranz;
	nrtranz = 0;
}

void Atm::loadbanifromfile()
{
	ifstream fin("bani.txt");
	char s[128];
	while (fin.getline(s, 128))
	{
		int bani = 0, apar = 0, cont = 1;
		char* p;
		p = strtok(s, " ");
		while (p != NULL)
		{
			if (cont == 1)
			{
				bani = atoi(p);
			}
			else if (cont == 2)
			{
				apar = atoi(p);
			}
			cont++;
			p = strtok(NULL, " ");
		}
		addBancnota(bani, apar);
	}
	fin.close();
}

void Atm::writetranztofile()
{
	ofstream fout("tranzactii.txt");
	for (int i = 1; i <= this->nrtranz; ++i)
	{
		Tranzactie tran = tranz[i];
		fout << tran.tostring();
		fout << endl;
		fout << "Bancnote folosite:";
		for (int j = 0; j < tranz[i].size(); j++)
		{
			fout << tranz[i].getel(j) << " ";
		}
		fout << endl << "In exemplare de: ";

		for (int j = 0; j < tranz[i].size(); j++)
		{
			fout << bancnote.nroccurrences(tranz[i].getel(j)) << ", ";
		}
		fout << endl << endl;
	}
	fout.close();
}

void Atm::writebanitofile()
{
	ofstream fout("bani.txt");
	for (int i = 0; i < this->bancnote.get_lungime(); i++)
	{
		fout << bancnote.get_val(i) << " " << bancnote.getAt(i) << endl;
	}
	fout.close();
}

int Atm::randomid()
{
	int random = rand();
	return random;
}

void Atm::addBancnota(int bill, int size)
{
	for (int i = 0; i < size; i++)
	{
		bancnote.add(bill);
	}
}

void Atm::showFunds()
{
	for (int i = 0; i < bancnote.get_lungime(); i++)
	{
		cout << "Bill: " << bancnote.get_val(i) << "; In number of: " << bancnote.nroccurrences(bancnote.get_val(i)) << endl;
	}
	if (bancnote.size() == 0) cout << "There are no bills!" << endl;
}

void Atm::addTranz()
{
	nrtranz++;

	int id;
	int suma;
	int bani[100] = { 0 };
	int ok;
	int n;

	id = randomid();
	cout << "Input sum you want to pay: ";
	cin >> suma;
	cout << "How many types of bills: ";
	cin >> n;
	cout << "Input bills: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> bani[i];
	}

	cout << "Choose method of payment: " << endl;
	tranz[nrtranz].add(id, suma, bani, n);

	ok = tranz[nrtranz].send();

	for (int i = 0; i < ok; i++)
	{
		bancnote.add(tranz[nrtranz].getvect(i));
	}
	
	writetranztofile();
	writebanitofile();
}

void Atm::showTranz()
{
	if (nrtranz != 0)
	{
		for (int i = 1; i <= nrtranz; i++)
		{
			cout << i << endl;
			cout << tranz[i].tostring() << endl;

			cout << "Used bills: ";

			for (int j = 0; j < tranz[i].size(); j++)
			{
				cout << tranz[i].getel(j) << " ";
			}

			cout << endl;
			cout << "In number of: ";

			for (int j = 0; j < tranz[i].size(); j++)
			{
				cout << bancnote.nroccurrences(tranz[i].getel(j)) << ", ";
			}
			cout << endl << endl;
		}
	}
	else
	{
		cout << "There are no transactions saved" << endl;
	}
}