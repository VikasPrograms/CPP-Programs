#include<iostream>
using namespace std;

int Addition(int i, int j)
{
    int Ans = 0;
    Ans = i + j;
    return Ans;
}

int main()
{
    int A = 11, B = 10, Sum = 0;

    Sum = Addition(A, B);

    cout<<"Addition is : "<<Sum<<"\n";
    
    return 0;
}