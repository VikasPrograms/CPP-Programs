//          Singly Linked List in C++.

// Create Class and Functions

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
        SinglyLL();         // Constructor

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

/*
Return_Value Class_Name :: Function_Name(Parameters)
{

}
*/

SinglyLL :: SinglyLL()      // Default Constructor
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: InsertFirst(int no)        // Parameterised Constructor
{}

void SinglyLL :: InsertLast(int no)        // Parameterised Constructor
{}

void SinglyLL :: InsertAtPosition(int no, int ipos)        // Parameterised Constructor
{}

void SinglyLL :: DeleteFirst()        // Default Constructor
{}

void SinglyLL :: DeleteLast()        // Default Constructor
{}

void SinglyLL :: DeleteAtPosition(int ipos)        // Parameterised Constructor
{}

void SinglyLL :: Display()        // Default Constructor
{}

int main()
{
    SinglyLL obj1;

    cout<<"Size of object : "<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains : "<<obj1.First<<"\n";
    cout<<"Number of nodes are : "<<obj1.iCount<<"\n";
    
    return 0;
}