// Problems on N numbers.

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int * Arr;  // int Arr[];            same syntax
        int iSize;

        ArrayX(int i)
        {
            iSize = i;
            Arr = new int[iSize];
        }

        void Accept()
        {
            cout<<"Please Enter the numbers : "<<"\n";
            int iCnt = 0;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()
        {
            cout<<"Elements of array are : "<<"\n";
            int iCnt = 0;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<"\n";
        }

        int SumEven()
        {
            int iSum = 0, iCnt = 0;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                if(Arr[iCnt] % 2 == 0)
                {
                    iSum = iSum + Arr[iCnt];
                }
            }
            return iSum;
        }

        int SumOdd()
        {
            int iSum = 0, iCnt = 0;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                if(Arr[iCnt] % 2 != 0)
                {
                    iSum = iSum + Arr[iCnt];
                }
            }
            return iSum;
        }
};

int main()
{
    int iLength = 0, iRet = 0;

    cout<<"Enter the number of elements : "<<"\n";
    cin>>iLength;

    ArrayX obj(iLength);

    obj.Accept();
    obj.Display();
    
    iRet = obj.SumEven();
    cout<<"Addition of Even elements : "<<iRet<<"\n";
    
    iRet = obj.SumOdd();
    cout<<"Addition of Odd elements : "<<iRet<<"\n";
    
    return 0;
}