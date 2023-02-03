// Singly Link List in Generic Code

#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>

struct node
{
    T data;
    struct node <T> *next;
};

// typedef is No Need for Generic Code

template<class T>

class SinglyLL
{
    public:
        struct node <T> *First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int iCount();
};

template<class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
}

template<class T>
void SinglyLL <T> :: Display()
{
    struct node <T> * temp = First;

    cout<<"Elements of SinglyLL is : ";

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

template<class T>
int SinglyLL <T> :: iCount()
{
    struct node <T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

template<class T>
void SinglyLL <T> :: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;

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

template<class T>
void SinglyLL <T> :: InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;
    struct node <T> * temp = First;

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

template<class T>
void SinglyLL <T> :: InsertAtPos(T no, int ipos)
{
    struct node<T> * newn = new struct node<T>;
    struct node <T> * temp = First;

    newn->data = no;
    newn->next = NULL;

    int iCnt = 0, NodeCnt = 0;
    NodeCnt = iCount();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position\n";
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

template<class T>
void SinglyLL <T> :: DeleteFirst()
{
    struct node <T> * temp = First;

    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        First = First->next;
        delete(temp);
    }
}

template<class T>
void SinglyLL <T> :: DeleteLast()
{
    struct node <T> * temp = First;

    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
}

template<class T>
void SinglyLL <T> :: DeleteAtPos(int ipos)
{
    struct node <T> * temp1 = First;
    struct node <T> * temp2 = NULL;

    int iCnt = 0, NodeCnt = 0;
    NodeCnt = iCount();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position \n";
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
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {   
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }
}

int main()
{
    SinglyLL <int> obj;
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