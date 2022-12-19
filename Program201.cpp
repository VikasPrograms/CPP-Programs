// Problems on Digits.

#include<iostream>
using namespace std;

class DigitX
{
    public:
        int iNo;

        DigitX()            // Default Constructor
        {
            iNo = 0;
        }

        DigitX(int i)       // Parameterised Constructor
        {
            iNo = i;
        }

        int SumEvenDigit()
        {
            int iSum = 0, iDigit = 0;
            int iTemp = iNo;
            
            while(iTemp != 0)
            {
                iDigit = iTemp % 10;
                if((iDigit % 2) == 0)
                {
                    iSum = iSum + iDigit;
                }
                iTemp = iTemp / 10;
            }
            return iSum;
        }
};

int main()
{
    int iValue = 0, iRet = 0;

    cout<<"Enter the Number : "<<"\n";
    cin>>iValue;

    DigitX obj(iValue);

    iRet = obj.SumEvenDigit();
    cout<<"Summation of even digits : "<<iRet<<"\n";

    cout<<obj.iNo;  // return old value is first input.

    return 0;
}