// Problems on Digits, Display maximum times occured digit and its frequency.

/*
    Input   :   45625656

    Output  :   Maximum times occured digit is 5 and its frequency is 3.
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

        void MaxFrequency()
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

            int iMaxFrequency = 0;
            int iMaxDigit = 0;

            for(int iCnt = 0; iCnt < 10; iCnt++)
            {
                if(Frequency[iCnt] > iMaxFrequency)
                {
                    iMaxFrequency = Frequency[iCnt];
                    iMaxDigit = iCnt;
                }
            }
            cout<<"Maximum times occured digit is "<<iMaxDigit<<" and its frequency is "<<iMaxFrequency<<"\n";
        }
};

int main()
{
    int iValue = 0, iRet = 0;

    cout<<"Enter the Number : "<<"\t";
    cin>>iValue;

    DigitX obj(iValue);

    obj.MaxFrequency();

    return 0;
}