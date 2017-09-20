#include <iostream>
#include <vector>
using namespace std;

template <class T>
T bigger(T a, T b){
    return (a>b?a:b);
}

template <class T>
T sum(const vector<T> &x){
    T sum = 0;
    for(int i = 0;i<x.size();i++){
        sum+=x.at(i);
    }
    return sum;
}
int main()
{
    cout<<bigger(4,6);

    return 0;
}
