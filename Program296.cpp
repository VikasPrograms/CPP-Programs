// Singly Linked List
// generalised customised data structure in C++

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

class SinglyLL
{
    public:
        PNODE First;

        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int iCount();
};

SinglyLL :: SinglyLL()
{
    First = NULL;
}

void SinglyLL :: Display()
{
    PNODE temp = First;

    cout<<"Elements of SinglyLL is : \t";

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

int SinglyLL :: iCount()
{
    PNODE temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

void SinglyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

void SinglyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void SinglyLL :: InsertAtPos(int no, int ipos)
{
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;

    int iCnt = 0, NodeCnt = 0;
    NodeCnt = iCount();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

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
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
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
    }

}

void SinglyLL :: DeleteAtPos(int ipos)        // Parameterised Constructor
{
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = iCount();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
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
    }
}

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(40);
    obj.Display();
    obj.InsertFirst(30);
    obj.Display();
    obj.InsertFirst(20);
    obj.Display();
    obj.InsertFirst(10);
    obj.Display();

    iRet = obj.iCount();
    cout<<"Number of nodes after Insert First are : "<<iRet<<"\n\n";

    obj.InsertLast(50);
    obj.Display();
    obj.InsertLast(60);
    obj.Display();
    obj.InsertLast(70);
    obj.Display();
    obj.InsertLast(80);
    obj.Display();

    iRet = obj.iCount();
    cout<<"Number of nodes after Insert Last are : "<<iRet<<"\n\n";

    obj.InsertAtPos(45, 5);
    obj.Display();

    iRet = obj.iCount();
    cout<<"Number of nodes after Insert At Position are : "<<iRet<<"\n\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.iCount();
    cout<<"Number of nodes after Delete First are : "<<iRet<<"\n\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.iCount();
    cout<<"Number of nodes after Delete Last are : "<<iRet<<"\n\n";

    obj.DeleteAtPos(4);
    obj.Display();

    iRet = obj.iCount();
    cout<<"Number of nodes after Delete At Position are : "<<iRet<<"\n\n";

    return 0;
}