// Copyright 2017 Vinogradova Ekaterina

#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>

using namespace std;

#define DefMemSize   25     // ������ ������ �� ���������

typedef double    TElem;    // ��� ��������
typedef TElem*    PTElem;
typedef double    TData;    // ��� ��������

class Deque
{
protected:
    PTElem pMem;      // ������ ��� ��
    int Front;
    int Back;
    int MemSize;      // ������ ������ ��� ��
    int DataCount;    // ���������� ��������� � ��

    int GetNextFrontIndex(int index);
    int GetNextBackIndex(int index);
public:
    Deque(int size = DefMemSize);
    ~Deque();
    void InsFront(TElem element);
    void InsBack(TElem element);
    TElem GetFront();
    TElem GetBack();
    bool IsEmpty(void) const;
    bool IsFull(void) const;
};

#endif  // DEQUE_H_
