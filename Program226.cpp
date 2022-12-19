//          Doubly Circular Linked List in C++.

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

class DoublyCLL
{
    public:
        PNODE First;
        PNODE Last;

        DoublyCLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyCLL :: DoublyCLL()
{
    First = NULL;
    Last = NULL;
}


int DoublyCLL :: Count()
{
    int iCnt = 0;
    PNODE temp = First;

    cout<<"Elements of the Linked List are : "<<"\n";
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Last->next);
    return iCnt;   
}

void DoublyCLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))       // CLL is empty
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else            // If CLL contains single or multiple node
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
        First->prev = Last;
        Last->next = First;
    }
}

void DoublyCLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))       // CLL is empty
    {
        First = Last = newn;
        Last->next = First;
    }
    else            // If CLL contains single or multiple node
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
        First->prev = Last;
        Last->next = First;
    }
}

void DoublyCLL :: InsertAtPos(int no, int ipos)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    int NodeCnt = 0, iCnt = 0;
    NodeCnt = Count();

    if((ipos < 0) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position "<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DoublyCLL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))     // Empty node
    {
        return;
    }
    else if(First == Last)    //  Single node
    {
        delete(First);       // free(*Last);
        First = NULL;
        Last = NULL;       // *First = *Last = NULL;
    }
    else            // Multiple node
    {
        First = First->next;
        First->prev = Last;
        Last->next = First;
    }
}

void DoublyCLL :: DeleteLast()
{
    PNODE temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete(First->prev);
        First->prev = Last;
        Last->next = First;
    }
}

void DoublyCLL :: DeleteAtPos(int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    NodeCnt = Count();

    if((ipos < 0) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position "<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt + 1)
    {
        DeleteLast();
    }
/*    else
    {
        PNODE temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
    }
*/
    else
    {
        PNODE temp1 = First;
        PNODE temp2 = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
        temp1->next->prev = temp1;
    }
}

void DoublyCLL :: Display()
{
    PNODE temp = First;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty "<<"\n";
        return;
    }

    cout<<"Elements of the Linked List are : "<<"\n";
    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;
    } while (temp != Last->next);
    cout<<"\n";
}

int main()
{
    int iRet = 0;
    DoublyCLL obj;

    obj.InsertFirst(40);
    obj.Display();
    obj.InsertFirst(30);
    obj.Display();
    obj.InsertFirst(20);
    obj.Display();
    obj.InsertFirst(10);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes After InsertFirst is : "<<iRet<<"\n\n";
    
    obj.InsertLast(50);
    obj.Display();
    obj.InsertLast(60);
    obj.Display();
    obj.InsertLast(70);
    obj.Display();
    obj.InsertLast(80);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes After InsertLast is : "<<iRet<<"\n\n";

    obj.InsertAtPos(45, 5);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes After InsertAtPos is : "<<iRet<<"\n\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes After DeleteFirst is : "<<iRet<<"\n\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes After DeleteLast is : "<<iRet<<"\n\n";

    obj.DeleteAtPos(4);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes After DeleteAtPos is : "<<iRet<<"\n\n";

    return 0;
}