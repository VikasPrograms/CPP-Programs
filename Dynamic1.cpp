#include<iostream>
using namespace std;

int main()
{
    int *p = NULL;

    p = new int[5];     // C++ & Java
    // p = (int *)malloc(5 * sizeof(int));

    // Use the memory

    delete []p;     // There is no such line in java
    // free(p);

    return 0;
}