#include<iostream>
using namespace std;

class Demo
{
    public:
        int i;
        int j;

        // Default constructor
        Demo()
        {
            i = 11;     // A(7)
            j = 21;     // A(8)
        }

        // Parametrised constructor
        Demo(int x, int y)
        {
            i = x;      // A(18)
            j = y;      // A(18)
        }
};

int main()
{
    Demo obj1;
    Demo obj2(10,20);
    
    const Demo obj3;
    const Demo obj4(10,20);

    obj1.i++;
    //obj4.i++;     NA
    //obj3.j++;     NA
    obj1.j++;

    return 0;
}