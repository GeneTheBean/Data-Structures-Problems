#include <iostream>
#include <Vector.h>
using namespace std;

int main()
{
    Vector <double> a;
    for(int i=0;i<20;i++)
        a.push_back(i);
    a.print();
    for(int i=0;i<10;i++)
        a.pop_back();
    a.print();
    a.erase(3,9);
    cout<<a.at(2);
}
