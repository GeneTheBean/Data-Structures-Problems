//This progran opens a file and uses a map to record the frequency of pairs and prints them in the end

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;
void printMap(map<pair<string, string>, int>& m);
map<pair<string, string>, int> pairCount;

int main(int argc, char *argv[])
{
    ifstream myfile("shakespeare-macbeth.txt");

    if(!myfile)
        cout<<"File not found.";

    else
    {
        string word = "", prevword;

        while(myfile >> word){
           std::string::iterator it;

           int count = 0;

           for(int i = 0;i<word.length(); i++){
                if(!isalpha(word[i]) && ((int)word[i] != 39))
                    word.erase(i);
                count++;
           }


           if(prevword == "")
                prevword = word;

           else{
                pairCount[pair<string,string>(prevword,word)]++;
                prevword = word;
           }
        }
    }
    printMap(pairCount);
    myfile.close();
    return 0;
}

void printMap(map<pair<string, string>, int>& m){
     cout<<"PAIR COUNT"<<endl;

        map<pair<string, string>, int>::iterator it;

        for(it = m.begin(); it != m.end(); it++){
            cout<<it->first.first
                <<", "
                <<it->first.second
                <<" : "
                <<it->second
                <<endl;
        }
}
