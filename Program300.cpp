// Stack -> Generic Code

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class Stack
{
    public:
        struct node <T> *First;
        int iCount;

        Stack();

        bool IsStackEmpty();         // Stack is Empty
        void Push(T no);             // Insert First
        T Pop();                     // Delete First
        void Display();
};

template<class T>
Stack <T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
bool Stack <T> :: IsStackEmpty()         // Stack is Empty
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

template<class T>
void Stack <T> :: Push(T no)        // Insert First
{
    struct node <T> *newn = new node <T>;

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

    cout<<no<<"  gets pushed in the stack successfully."<<"\n";
}

template<class T>
T Stack <T> :: Pop()            // Delete Last
{
    struct node <T> * temp = First;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is Empty."<<"\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct node <T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void Stack <T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty."<<"\n";
    }
    else
    {
        cout<<"Elements of stack are : "<<"\n";

        struct node <T> *temp = First;

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
    Stack <int> obj;

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