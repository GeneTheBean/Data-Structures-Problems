#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<pair<string,string>,double> m;
    m.insert(pair<pair<string,string>,double>(std::make_pair("New York", "New York City"), 0));
    m.insert(pair<pair<string,string>,double>(std::make_pair("Illinois", "Chicago"), 2.7));
    m[pair<string,string>("New York", "New York City")] += 8.4;
    m.insert(pair<pair<string,string>,double>(std::make_pair("Canada", "Ontario"), 1.6));

    map<pair<string,string>,double>::iterator it;
    for(it = m.begin();it!=m.end();it++){
        cout<<"The population of "<<it->first.first<<", "<<it->first.second
        <<" is approximately "<< it->second <<" million."<<endl;
    }
    return 0;
}


