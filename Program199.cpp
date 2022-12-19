// Problems on Minimum.

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

class MarvellousLB : public ArrayX          // Inherit class ArrayX
{
    public : 

        MarvellousLB(int i) : ArrayX(i)     // Base Member Initialisation.  // Constructor
        {
        }

        int Minimum()
        {
            int iMin = Arr[0];

            for(int iCnt = 0; iCnt < iSize; iCnt++)
            {
                if(Arr[iCnt] < iMin)
                {
                    iMin = Arr[iCnt];
                }
            }
            return iMin;
        }
};

int main()
{
    int iLength = 0, iRet = 0;

    cout<<"Enter the size of array : "<<"\n";
    cin>>iLength;

    MarvellousLB * obj = new MarvellousLB(iLength);

    obj->Accept();
    obj->Display();

    iRet = obj->Minimum();

    cout<<"Smallest element is : "<<iRet<<"\n";

    delete obj;

    return 0;
}