// First Method of Array list.

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int * Arr;
        int iSize;

        ArrayX(int i)       // Constructor
        {
            iSize = i;
            Arr = new int[iSize];       // Arr = (int *)malloc(iSize * sizeof(int));
        }

        ~ArrayX()           // Distructor
        {
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
    ArrayX obj(5);      // Static & Hardcoded

    obj.Accept();
    obj.Display();

    return 0;
}