// Problems on Digits.

/*
    Input   :   4562565

    Output  :   2 occurs at 1 times
                4 occurs at 1 times
                5 occurs at 3 times
                6 occurs at 2 times
*/

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

        void DisplayFrequency()
        {
            int iTemp = iNo;
            int iDigit = 0;
            int Frequency[10] = {0};

            while(iTemp != 0)           
            {
                iDigit = iTemp % 10;
                Frequency[iDigit]++;
                iTemp = iTemp / 10;
            }

            for(int iCnt = 0; iCnt < 10; iCnt++)
            {
                if(Frequency[iCnt] > 0)
                {
                    cout<<iCnt<<" occurs at "<<Frequency[iCnt]<<" times"<<"\n";
                }
            }
        }
};

int main()
{
    int iValue = 0, iRet = 0;

    cout<<"Enter the Number : "<<"\t";
    cin>>iValue;

    DigitX obj(iValue);

    obj.DisplayFrequency();

    return 0;
}