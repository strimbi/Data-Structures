#include <iostream>
#include <vector>
#include "teste.h"
#include "List.h"
#include "Node.h"
#include <cassert>

void Test::test_constructor()
{
    VectorDinamic<int> v(3);
    try
    {
        VectorDinamic<int> u(-3);
        assert(false);
    }
    catch (std::invalid_argument ex) 
    {
        assert(true);
    }

}

void Test::test_size()
{
    VectorDinamic<int> v(10);
    assert(v.size() == 0);
    v.push_back(4);
    v.push_back(5);
    assert(v.size() == 2);
}

void Test::test_push_back() 
{
    VectorDinamic<int> v(3);
    v.push_back(4);
    v.push_back(5);
    assert(v.size() == 2);
}


void Test::testInsert()
{
    List<int> l;
    l.push_back(5);
    l.push_back(10);
    l.insert(7, 1);
    assert(l.getAt(1) == 10);
}

void Test::testPush()
{
    List<int> l;
    l.push_back(5);
    l.push_back(10);
    l.push(1);
    assert(l.getAt(0) == 1);
}

void Test::testPushBack() 
{
    List<int> l;
    l.push_back(5);
    assert(l.size() == 1);
    l.push_back(10);
    assert(l.size() == 2);
    assert(l.getAt(1) == 10);

}

void Test::testRemove()
{
    List<int> l;
    l.push_back(5);
    l.push_back(10);
    l.push_back(15);
    l.remove(1);
    assert(l.getAt(0) == 5);
    assert(l.getAt(1) == 15);
    assert(l.size() == 2);
}

void Test::testUpdate()
{
    List<int> l;
    l.push_back(5);
    l.push_back(10);
    l.push_back(15);
    l.update(-15, 2);
    assert(l.getAt(2) == -15);
}

void Test::testSize() 
{
    List<int> l;
    assert(l.size() == 0);
    l.push_back(5);
    l.push_back(10);
    assert(l.size() == 2);
    l.push_back(15);
    assert(l.size() == 3);
}

void Test::testgetAt()
{
    List<int> l;
    l.push_back(5);
    l.push_back(10);
    assert(l.getAt(1) == 10);
}

void Test::testAll() 
{
    //test_constructor();
    testSize();
    testgetAt();
    testUpdate();
    testRemove();
    testInsert();
    testPush();
    testPushBack();
    test_size();
    test_push_back();
}