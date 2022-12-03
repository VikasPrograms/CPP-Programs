#include<iostream>
using namespace std;
//Class Declaration
class Maths
{
    public:                 //Access Specifier
        int iNo1;           //Characteristics
        int iNo2;           //Characteristics
    
    Maths()                 //Constructor (Default)     //Text Section Start
    {
        cout<<"Inside default constructor\n";
        iNo1 = 0;
        iNo2 = 0;
    }
    
    Maths(int A, int B)      //Constructor (Parametrised)
    {
        cout<<"Inside parametrised constructor\n";
        iNo1 = A;
        iNo2 = B;
    }

    ~Maths()
    {
        //Destructor
    }
    //int Addition(Maths *this)
    int Addition()            //Behaviour
    {
        return iNo1 + iNo2;
    }
    //int Substraction(Maths *this)
    int Substraction()         //Behaviour
    {
        return iNo1 - iNo2;
    }                                                     //Text Section End
};

int main()
{
    cout<<"Inside main function\n";

    Maths mobj1;            //Storage class Auto    //Local variable
    Maths mobj2(11,10);
    int ret = 0;

    ret = mobj2.Addition();     //ret = Addition(&mobj2);   //ret = Addition(200);
    cout<<"Addition is : "<<ret<<"\n";

    ret = mobj1.Addition();     //ret = Addition(&mobj1)    //ret = Substraction(100);
    cout<<"Addition is : "<<ret<<"\n";

    return 0;
}