#ifndef VECTORDINAMIC_H
#define VECTORDINAMIC_H
#include <iostream>

using namespace std;

template<class TypeData>
class VectorDinamic
{
private:
    TypeData* elements;
    int nrElems;
    int capacity;
    void resize();

public:
    VectorDinamic();
    VectorDinamic(int capacitate);

    int size() const; 

    void Destructor();
    void push_back(TypeData e);
    void addAt(int i, TypeData e);

    TypeData getAt(int i) const;
    TypeData update(int i, TypeData e);
    TypeData sterge(int i);
    
};

template<class TypeData>
void VectorDinamic<TypeData>::Destructor()
{
    delete[] this->elements;
    this->nrElems = 0;
    this->capacity = 0;
}

template<class TypeData>
VectorDinamic<TypeData>::VectorDinamic()
{
    this->nrElems = 0;
    this->capacity = 0;
    this->elements = new TypeData[capacity]; 
}

/// Redimenstioneaza vectorul de elemente de tip TypeData
template<class TypeData>
void VectorDinamic<TypeData>::resize()
{
    this->capacity = this->capacity * 2;
    TypeData* aux = new TypeData[this->capacity];
    for (int i = 0; i < this->nrElems; i++)
        aux[i] = elements[i];
    this->elements = aux;
}

/// Construieste un vector de elemente de tipul TypeData
template<class TypeData>
VectorDinamic<TypeData>::VectorDinamic(int capacitate)
{
    this->capacity = capacitate;
    this->elements = new TypeData[capacitate];
    this->nrElems = 0;
}


/// \return numarul de elemente din vector
template<class TypeData>
int VectorDinamic<TypeData>::size() const
{
    return this->nrElems;
}

/// \return elementul aflat pe pozitia i
template<class TypeData>
TypeData VectorDinamic<TypeData>::getAt(int i) const
{
   return this->elements[i];
}

/// Actualizeaza elementul de pe pozitia i cu elementul e
/// \param i , 0 <= i< numarul de elemente ale vectorului
/// \param e , element de tip TypeData,
/// \return returneaza vechea valoare a elementului aflat pe pozitia i
template<class TypeData>
TypeData VectorDinamic<TypeData>::update(int i, TypeData e)
{
    TypeData aux = elements[i];
    this->elements[i] = e;
    return aux;
}

/// Adauga elementul e la finalul vectorului
template<class TypeData>
void VectorDinamic<TypeData>::push_back(TypeData e)
{
    if(this->capacity==this->nrElems)
         resize();
    this->elements[nrElems] = e;
    this->nrElems++;
}

/// Adauga pe pozitia i elementul e
template<class TypeData>
void VectorDinamic<TypeData>::addAt(int i, TypeData e)
{
    if (i == this->nrElems and this->nrElems == this->capacity)
        resize();
    int j = this->nrElems;
    this->nrElems++;
    while (j > i)
        this->elements[j] = this->elements[j - 1], j--;
    this->elements[i] = e;
}

/// Sterge elementul aflat pe pozitia i
template<class TypeData>
TypeData VectorDinamic<TypeData>::sterge(int i)
{
    TypeData aux = this->elements[i];
    this->elements[i] = this->elements[--this->nrElems];
    return aux;
}

#endif //VECTORDINAMIC_H