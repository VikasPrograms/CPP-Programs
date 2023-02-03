// Singly Link List
// Using integer, float, double

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

    cout<<"Elements of SinglyLL is : \t";

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

int main()
{
    SinglyLL <char>cobj;
    char cRet = 0;

    cobj.InsertFirst('b');
    cobj.Display();
    cobj.InsertFirst('a');
    cobj.Display();
    cRet = cobj.iCount();
    cout<<"Number of nodes are : "<<cRet<<"\n\n";

    SinglyLL <int> iobj;
    int iRet = 0;

    iobj.InsertFirst(40);
    iobj.Display();
    iobj.InsertFirst(30);
    iobj.Display();
    iobj.InsertFirst(20);
    iobj.Display();
    iobj.InsertFirst(10);
    iobj.Display();

    iRet = iobj.iCount();
    cout<<"Number of nodes after Insert First are : "<<iRet<<"\n\n";

    SinglyLL <float> fobj;
    float fRet = 0.0f;

    fobj.InsertFirst(40.2f);
    fobj.Display();
    fobj.InsertFirst(30.2f);
    fobj.Display();
    fobj.InsertFirst(20.2f);
    fobj.Display();
    fobj.InsertFirst(10.2f);
    fobj.Display();

    fRet = fobj.iCount();
    cout<<"Number of nodes after Insert First are : "<<fRet<<"\n\n";

    SinglyLL <double> dobj;
    double dRet = 0.0;

    dobj.InsertFirst(40.12);
    dobj.Display();
    dobj.InsertFirst(30.12);
    dobj.Display();
    dobj.InsertFirst(20.12);
    dobj.Display();
    dobj.InsertFirst(10.12);
    dobj.Display();

    dRet = dobj.iCount();
    cout<<"Number of nodes after Insert First are : "<<dRet<<"\n\n";


    return 0;
}