#include "collection.h"
#include <iostream>

using namespace std;

typedef int TElem;

Collection::Collection() 
{
    this->distinctelements = 0;
    this->capacity = 0;
}

void Collection::Destructor()
{
    this->capacity = 0;
    this->distinctelements = 0;
    this->elements.Destructor();
}

void Collection::resize()
{
    this->capacity = this->capacity * 2;

    Element* new_elems = new Element[this->capacity];
    for (int i = 0; i < this->distinctelements; i++)
        new_elems[i] = this->elements.getAt(i);

    for (int i = 0; i < this->capacity; i++)
        this->elements.push_back(new_elems[i]);
}

void Collection::add(TElem elem)
{
    if (search(elem)) 
    {
        int ok = 1;
        for (int i = 0; i < this->distinctelements && ok; i++)
            if (this->elements.getAt(i).valoare == elem)
            {
                int nrAparitii = this->elements.getAt(i).nr_aparitii + 1;
                Element elem2;
                elem2.valoare = elem;
                elem2.nr_aparitii = nrAparitii;
                this->elements.update(elem2, i);
                ok = 0;
            }
    }
    else 
    {
        if (this->distinctelements == capacity)
            resize();
        Element elem2;
        elem2.valoare = elem;
        elem2.nr_aparitii = 1;
        this->elements.push_back(elem2);
        this->distinctelements++;
    }
}

bool Collection::remove(TElem elem) 
{
    if (search(elem))
    {
        int i = 0;
        while (this->elements.getAt(i).valoare != elem)
            i++;
        for (int j = i; j < this->distinctelements - 1; j++) 
        {
            this->elements.update(this->elements.getAt(j + 1), j);
        }
        this->distinctelements--;
        return true;
    }
    return false;
}

bool Collection::search(TElem elem)
{
    for (int i = 0; i < this->distinctelements; i++)
        if (this->elements.getAt(i).valoare == elem)
            return true;
    return false;
}

int Collection::size()
{
    int sum = 0;
    for (int i = 0; i < this->distinctelements; i++)
        sum = sum + this->elements.getAt(i).valoare * this->elements.getAt(i).nr_aparitii;
    return sum;
}

int Collection::nroccurrences(TElem elem) 
{
    if (search(elem))
    {
        int i = 0;
        while (this->elements.getAt(i).valoare != elem)
            i++;
        return this->elements.getAt(i).nr_aparitii;
    }
    return -1;
}

int Collection::getAt(int position)
{
    return this->elements.getAt(position).nr_aparitii;
}

TElem Collection::get_val(int position)
{
    return this->elements.getAt(position).valoare;
}

int Collection::get_lungime()
{
    return this->distinctelements;
}