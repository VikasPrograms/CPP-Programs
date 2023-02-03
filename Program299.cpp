// Stack -> Specific Code

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

class Stack
{
    public:
        struct node * First;
        int iCount;

        Stack();                // Constructor

        bool IsStackEmpty();    // Stack is empty 
        void Push(int no);      // Insert
        int Pop();              // Delete
        void Display();
};

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

bool Stack :: IsStackEmpty()         // Stack is Empty
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack :: Push(int no)      // Logic of Insert First
{
    struct node * newn = new node;

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

    iCount++;

    cout<<no<<"  gets pushed in the stack successfully"<<"\n";
}

int Stack :: Pop()              // Logic of Delete First
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty."<<"\n";
        return -1;
    }
    else
    {
        int value = First->data;
        struct node * temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

void Stack :: Display()
{
    if(First == NULL)
    {
        cout<<"Staci is Empty."<<"\n";
    }
    else
    {
        cout<<"Elements of stack are : "<<"\n";

        struct node * temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp->next;
        }
        cout<<" NULL"<<"\n\n";
    }
}

int main()
{
    Stack obj;

    obj.Push(40);
    obj.Display();
    obj.Push(30);
    obj.Display();
    obj.Push(20);
    obj.Display();
    obj.Push(10);
    obj.Display();

    int iRet = obj.Pop();
    cout<<"Poped Element is : "<<iRet<<"\n";
    obj.Display();

    iRet = obj.Pop();
    cout<<"Poped Element is : "<<iRet<<"\n";
    obj.Display();

    return 0;
}