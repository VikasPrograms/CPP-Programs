//          Singly Linked List in C++.
// Create Class

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
        PNODE First;        // size of object 8 bytes

        // Behaviours
        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
};

int main()
{
    SinglyLL obj;

    return 0;
}