//This progran opens a file and uses a map to record the frequency of each word and prints them in the end

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;
void printMap(map<string, int>& m);
map<string, int> wordCount;

int main(int argc, char *argv[])
{
    ifstream myfile("austen-emma.txt");

    if(!myfile)
        cout<<"File not found.";

    else
    {
        string word = "";

        while(myfile >> word){
           std::string::iterator it;

           int count = 0;
           for(int i = 0;i<word.length(); i++){
                if(!isalpha(word[i]) && ((int)word[i] != 39))
                    word.erase(i);
                count++;
           }

           wordCount[word]++;
        }
    }

    printMap(wordCount);

    myfile.close();
    return 0;
}

void printMap(map<string, int>& m){
     cout<<"WORD COUNT"<<endl;

        map<string, int>::iterator it;

        for(it = m.begin(); it != m.end(); it++){
            cout<<it->first
                <<" : "
                <<it->second
                <<endl;
        }
}
