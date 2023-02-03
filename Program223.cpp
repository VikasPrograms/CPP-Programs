//          Singly Circular Linked List in C++

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
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
    public:
        PNODE First;
        PNODE Last;

        SinglyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

SinglyCL :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

void SinglyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;              // PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

void SinglyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

void SinglyCL :: DeleteFirst()
{
    PNODE temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    {
        delete First;        //free(First);
        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        First = (First)->next;
        delete temp;                //free(temp);
        (Last) ->next = First;
    }
}

void SinglyCL :: DeleteLast()
{
    PNODE temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    { 
        delete First;            //free(temp);
        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }
        delete temp->next;        //free(temp->next);   // free(*Last);
        Last = temp; 
        (Last) ->next = First;
    }
}

void SinglyCL :: Display()
{
    PNODE temp  = First;
    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"*First \n";
}

int SinglyCL :: Count()
{
    PNODE temp  = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

void SinglyCL :: InsertAtPos(int no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    PNODE newn = NULL;
    PNODE temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;        //newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void SinglyCL :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    PNODE temp1 = First;
    PNODE temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;
        temp1->next = temp2->next;
        delete temp2;        //free(temp2);
    }
}

int main()
{
    SinglyCL obj;

    int iRet = 0;
    
    obj.InsertFirst(40);
    obj.Display();
    obj.InsertFirst(30);
    obj.Display();
    obj.InsertFirst(20);
    obj.Display();
    obj.InsertFirst(10);
    obj.Display();
    iRet = obj.Count();
    printf("Number of elements are InsertFirst : %d\n\n",iRet);

    obj.InsertLast(50);
    obj.Display();
    obj.InsertLast(60);
    obj.Display();
    obj.InsertLast(70);
    obj.Display();
    obj.InsertLast(80);
    obj.Display();
    iRet = obj.Count();
    printf("Number of elements are InsertLast : %d\n\n",iRet);

    obj.InsertAtPos(55,6);
    obj.Display();
    iRet = obj.Count();
    printf("Number of elements are InsertAtPos : %d\n\n",iRet);

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    printf("Number of elements are DeleteFirst : %d\n\n",iRet);

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    printf("Number of elements are DeleteLast : %d\n\n",iRet);

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    printf("Number of elements are DeleteAtPos : %d\n\n",iRet);

    return 0;
}