#include <iostream>

using namespace std;

int main()
{
    baseCL bObj
    derivedCL d1Obj(8), d2Obj;

    bObj.output();
}
class baseCL
{
public:
baseCL(): dataBCL(5)
{}
void output()
{    cout << dataBCL << "  "; }
protected:
int dataBCL;
};
class derivedCL: public baseCL
{
public:
derivedCL(int n = 1): dataDCL(n)
{ dataBCL = n + 1; }
void output()
{     baseCL::output();
cout << dataDCL  << endl;
}
private:
int dataDCL;
};
int main()
{
baseCL bObj;
derivedCL d1Obj(8), d2Obj;
