#include<iostream>
using namespace std;

float Addition(float i, float j)
{
    float Ans = 0.0f;
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