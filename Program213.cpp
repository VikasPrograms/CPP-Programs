//          Singly Linked List in C++;

// Create Class and Functions.
// Create returns of main functions.
// Insert First & Last.
// Delete First & Last.

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
{
    // Step 1 : Allocate memory for node
    PNODE newn = new NODE;

    // Step 2 : Initialise node
    newn->data = no;
    newn->next = NULL;

    // Step 3 : Check if LL is empty or not
    if(First == NULL)       // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

void SinglyLL :: InsertLast(int no)        // Parameterised Constructor
{
    // Step 1 : Allocate memory for node
    PNODE newn = new NODE;

    // Step 2 : Initialise node
    newn->data = no;
    newn->next = NULL;

    // Step 3 : Check if LL is empty or not
    if(First == NULL)       // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one node
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        iCount++;
    }

}

void SinglyLL :: InsertAtPosition(int no, int ipos)        // Parameterised Constructor
{}

void SinglyLL :: DeleteFirst()        // Default Constructor
{
    if(First == NULL)       // if(iCount == 0)
    {
        return;
    }
    else if(First->next == NULL)        // else if(iCount ==1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
        iCount--;
    }
}

void SinglyLL :: DeleteLast()        // Default Constructor
{
    if(First == NULL)       // if(iCount == 0)
    {
        return;
    }
    else if(First->next == NULL)        // else if(iCount ==1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        iCount--;
    }

}

void SinglyLL :: DeleteAtPosition(int ipos)        // Parameterised Constructor
{}

void SinglyLL :: Display()        // Default Constructor
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;

    cout<<"Size of object : "<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains : "<<obj1.First<<"\n";
    cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

    cout<<"Linked list of first object is : "<<"\n";  
    
    obj1.InsertFirst(51);
    obj1.Display();

    obj1.InsertFirst(21);
    obj1.Display();

    obj1.InsertFirst(11);
    obj1.Display();
    
    cout<<"Number of InsertFirst nodes are : "<<obj1.iCount<<"\n\n";

//----------------------------------------------------------------------------------

    obj1.InsertLast(101);
    obj1.Display();

    obj1.InsertLast(111);
    obj1.Display();

    obj1.InsertLast(121);
    obj1.Display();
    
    cout<<"Number of InsertLast nodes are : "<<obj1.iCount<<"\n";

//----------------------------------------------------------------------------------

    obj1.DeleteFirst();
    obj1.Display();
    
    cout<<"Number of DeleteFirst nodes are : "<<obj1.iCount<<"\n";

//----------------------------------------------------------------------------------

    obj1.DeleteLast();
    obj1.Display();
    
    cout<<"Number of DeleteLast nodes are : "<<obj1.iCount<<"\n";
    
    return 0;
}