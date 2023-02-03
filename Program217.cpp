//          Doubly Linked List in C++;      (HomeWork)

// Create Class and Functions.
// Create returns of main functions.
// Insert First & Last.
// Delete First & Last.
// InsertAtPosition & DeleteAtPosition.

#include<iostream>
using namespace std;
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLL
{
    public:
        PNODE First;
        int iCount;

        DoublyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

DoublyLL :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
        iCount++;
    }
}

void DoublyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyLL :: InsertAtPosition(int no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        temp->prev = newn;
        iCount++;
    }
}

void DoublyLL :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;

        First = First->next;
        delete (First -> prev);
        First->prev = NULL;
        iCount--;
    }
}

void DoublyLL :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
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

void DoublyLL ::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid Position "<<"\n";
        return;
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        PNODE temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        temp1->next->prev = temp1;
        iCount--;
    }
}

void DoublyLL :: Display()
{
    cout<<"Elements of Linked List are : \n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    DoublyLL obj;

    cout<<"Linked list of First object is : "<<"\n";

    obj.InsertFirst(40);
    obj.Display();
    obj.InsertFirst(30);
    obj.Display();
    obj.InsertFirst(20);
    obj.Display();
    obj.InsertFirst(10);
    obj.Display();
    cout<<"Number of InsertFirst nodes are : "<<obj.iCount<<"\n\n";

    obj.InsertLast(50);
    obj.Display();
    obj.InsertLast(60);
    obj.Display();
    obj.InsertLast(70);
    obj.Display();
    obj.InsertLast(80);
    obj.Display();
    cout<<"Number of InsertLast nodes are : "<<obj.iCount<<"\n\n";

    obj.InsertAtPosition(55,6);
    obj.Display();
    cout<<"Number of InsertAtPosition nodes are : "<<obj.iCount<<"\n\n";

    obj.DeleteFirst();
    obj.Display();
    cout<<"Number of DeleteFirst nodes are : "<<obj.iCount<<"\n\n";

    obj.DeleteLast();
    obj.Display();
    cout<<"Number of DeleteLast nodes are : "<<obj.iCount<<"\n\n";

    obj.DeleteAtPosition(5);
    obj.Display();
    cout<<"Number of DeleteAtPosition nodes are : "<<obj.iCount<<"\n\n";

    return 0;
}