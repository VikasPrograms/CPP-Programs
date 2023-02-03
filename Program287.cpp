#include<iostream>
using namespace std;

void Swap(int &x, int &y)         // call by reference
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void Swapd(double &x, double &y)
{
    double temp;

    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 11, b = 10;

    cout<<"Value of a "<<a<<"\n";
    cout<<"Value of b "<<b<<"\n";

    Swap(a,b);
    cout<<"-----------------------------\n";

    cout<<"Value of a "<<a<<"\n";
    cout<<"Value of b "<<b<<"\n";

    double p = 11.9, q = 10.1;

    cout<<"-----------------------------\n";

    cout<<"Value of p "<<p<<"\n";
    cout<<"Value of q "<<q<<"\n";

    Swapd(p,q);
    cout<<"-----------------------------\n";

    cout<<"Value of p "<<p<<"\n";
    cout<<"Value of q "<<q<<"\n";

    return 0;
}