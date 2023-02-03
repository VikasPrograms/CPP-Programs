//          Singly Linked List in C++.

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
    // Chatacteristics
        PNODE First;        // size of object 8 Bytes
        int iCount;         // size of object 4 Bytes

    // Behaviours
        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;
    
    return 0;
}