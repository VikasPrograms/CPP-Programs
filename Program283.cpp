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
    int A = 11, B = 10, Sum = 0;
    Sum = Addition(A, B);
    cout<<"Addition is : "<<Sum<<"\n";
    
    float X = 11.9f, Y = 10.2f, iSum = 0.0f;
    iSum = Addition(X, Y);
    cout<<"Addition is : "<<iSum<<"\n";
    
    double M = 11.9, N = 10.1, aSum = 0.0;
    aSum = Addition(M, N);
    cout<<"Addition is : "<<aSum<<"\n";
    
    return 0;
}