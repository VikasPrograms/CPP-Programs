#include<iostream>
using namespace std;

class Base
{
    public:             // Access specifier
        int A,B;

        void fun()                  // Function defination          1000
        {
            cout<<"Base fun\n";
        }
        void gun(int i)             // Function defination          2000
        {
            cout<<"Base gun with one integer\n";
        }
        void gun(int i, int j)      // Overloaded Function defination       3000
        {
            cout<<"Base gun with two integer\n";
        }
};

class Derived : public Base
{
    public:
        int X,Y;

        void sun()         // Function defination                   4000
        {
            cout<<"Derived sun\n";
        }
        void fun()         // Function redefination                 5000
        {
            cout<<"Derived fun\n";
        }
};

int main()
{
    Derived dobj;
    dobj.fun();             // Call---------5000
    dobj.gun(11);           // Call---------2000
    dobj.gun(11,12);        // Call---------3000
    dobj.sun();             // Call---------4000

    return 0;
}