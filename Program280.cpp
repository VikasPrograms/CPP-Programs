#include<iostream>
using namespace std;

double Addition(double i, double j)
{
    double Ans = 0.0;
    Ans = i + j;
    return Ans;
}

int main()
{
    double A = 11.9, B = 10.1, Sum = 0.0;

    Sum = Addition(A, B);

    cout<<"Addition is : "<<Sum<<"\n";
    
    return 0;
}