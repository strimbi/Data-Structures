#include "tranzactie.h"
#include "collection.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

int x[100], a[100], n, s, k = 0;
int metoda = 0;
int v[100];
int ok = 0;

Tranzactie::Tranzactie()
{
    this->suma = 0;
    this->idTranzactie = 0;
}

Tranzactie::~Tranzactie() {}

int Tranzactie::size()
{
    return this->bancnote.get_lungime();
}

int Tranzactie::getel(int poz)
{
    return bancnote.get_val(poz);
}

void Tranzactie::add(int id, int suma, int bani[], int n)
{
    this->suma = suma;
    this->idTranzactie = id;
    for (int i = 0; i < n; i++)
    {
        this->bancnote.add(bani[i]);
    }
    
    citire(suma, n);
    k = 0;
    metoda = 0;
    backtrack(1, 0);
    metodaselect();
}

int Tranzactie::send()
{
    return ok;
}

int Tranzactie::getvect(int poz)
{
    for (int i = 0; i < ok; i++)
    {
        if (poz == i) return v[i];
    }
    return -1;
}

void Tranzactie::citire(int suma, int nr)
{
    n = nr;
    for (int i = 1; i <=n; i++)
    {
        a[i] = bancnote.get_val(i-1);
    }
    s = suma;
}

void Tranzactie::metodaselect()
{
    cin >> metoda;
    k = 0;
    backtrack(1, 0);
}

void Tranzactie::afisvar2()
{
    k++;
    if (metoda)
    {
        if (k == metoda)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= x[i]; j++)
                {
                    v[ok] = a[i];
                    ok++;
                }
            }
        }
    }
    else afis();
}

void Tranzactie::afis()
{
    cout << "Metoda " << k << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << "*" << a[i] << " ";
    }
    cout << endl;
}

void Tranzactie::backtrack(int k, int sp)
{
    int i;
    for (i = 1; i <= (s - sp) / a[k]; i++)
    {
        x[k] = i;
        sp = sp + x[k] * a[k];
        if (sp <= s && k <= n) if (k == n && sp == s) afisvar2();
        else if (k < n) backtrack(k + 1, sp);
        sp = sp - x[k] * a[k];
    }
}

std::string Tranzactie::tostring()
{
    std::stringstream s1;
    s1 << this->idTranzactie;
    std::string str1 = s1.str();

    std::stringstream s2;
    s2 << this->suma;
    std::string str2 = s2.str();

    return "Id= " + str1 + "\n" + "Suma= " + str2;
}

int Tranzactie::getsuma()
{
    return this->suma;
}

int Tranzactie::getid()
{
    return this->idTranzactie;
}