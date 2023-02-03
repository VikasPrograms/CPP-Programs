#include<iostream>
using namespace std;

void Swap(int *x, int *y)         // call by address  // Pointer *
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 11, b = 10;

    cout<<"Value of a "<<a<<"\n";
    cout<<"Value of b "<<b<<"\n";

    Swap(&a,&b);            // changes by address
    cout<<"-----------------------------\n";

    cout<<"Value of a "<<a<<"\n";
    cout<<"Value of b "<<b<<"\n";

    return 0;
}