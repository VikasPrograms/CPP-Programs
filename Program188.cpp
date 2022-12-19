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

        void Function() // Function whichj contains business logic
        {
            // Logic
        }
};

int main()
{
    int iLength = 0;

    cout<<"Enter the number of elements : "<<"\n";
    cin>>iLength;

    ArrayX obj(iLength);

    obj.Accept();
    obj.Display();
    obj.Function();
    
    return 0;
}