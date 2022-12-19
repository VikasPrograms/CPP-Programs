// Second Method for Array list input users.

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int * Arr;
        int iSize;

        ArrayX(int i)       // Constructor
        {
            cout<<"Allocating the memory for resources..."<<"\n";

            iSize = i;
            Arr = new int[iSize];       // Arr = (int *)malloc(iSize * sizeof(int));
        }

        ~ArrayX()           // Distructor
        {
            cout<<"Deallocating the memory for resources..."<<"\n";

            delete []Arr;
        }

        void Accept()       // Getter
        {
            cout<<"Enter the Elements of array : "<<"\n";

            for(int iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];        // scanf("%d",&Arr[i]);
            }
        }

        void Display()       // Setter
        {
            cout<<"Elements of array are : "<<"\n";

            for(int iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";      //  printf("%d\t",Arr[iCnt]);
            }
            cout<<"\n";
        }
};

int main()
{
    int iLength = 0;

    cout<<"Enter the size of array : "<<"\n";
    cin>>iLength;

    ArrayX obj(iLength);      // Static

    obj.Accept();
    obj.Display();

    return 0;
}