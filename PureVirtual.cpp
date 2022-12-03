#include<iostream>
using namespace std;

class circle
{
    public:                 // Access specifier
        float PI;               // Characteristics
        float Radius;          // Characteristics

        circle()                // Default Constructor
        {
            PI = 3.14;
            Radius = 0.0;
        }
        circle(float A, float B)        // Parameterised Constructor
        {
            PI = A;
            Radius = B;
        }
        void Display()          // Concrete method  // 1000
        {
            cout<<"Value of Radius is : "<<Radius<<"\n";
        }
        virtual float Area() = 0;               // Abstract method      //
        virtual float Circumfarence() = 0;      // Abstract method      //
};

class Marvellous : public circle
{
    public:
        Marvellous() : circle()
        {}
        Marvellous(float X, float Y) : circle(X,Y)
        {}
        float Area()            // Concrete method      // 2000
        {
            float Ans = PI * Radius* Radius;
            return Ans;
        }
        float Circumfarence()       // Concrete method      // 3000
        {
            float Ans = 0.0;
            Ans = 2 * PI * Radius;
            return Ans;
        }
};

int main()
{
    Marvellous mobj1;
    Marvellous mobj2(3.14, 10.89);

    float fret = 0.0;

    fret = mobj2.Area();
    cout<<"Area is : "<<fret<<"\n";

    fret = mobj2.Circumfarence();
    cout<<"Circumfarence is : "<<fret<<"\n";

    return 0;
}