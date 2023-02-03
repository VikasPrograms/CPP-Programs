#include<iostream>
using namespace std;

void Display(int Arr[], int iSize)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
}

int main()
{
    int Data[] = {10,20,30,40};

    Display(Data, 4);

    return 0;
}