// Generic Code

#include<iostream>
using namespace std;

template <class T>

T Addition(T i, T j)
{
    T Ans;
    Ans = i + j;
    return Ans;
}

int main()
{
    float A = 11.9f, B = 10.2f, Sum = 0.0f;

    Sum = Addition(A, B);

    cout<<"Addition is : "<<Sum<<"\n";
    
    return 0;
}