// Name: Eugene Chen

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void calc_bigrams(const char*, map<pair<string, string>, float>&);

int main(int argc, char* argv[]) {
	map<pair<string, string>, float> bigram_map;
	calc_bigrams("shakespeare-macbeth.txt", bigram_map);

	cout << bigram_map[pair<string, string>("with", "me")] << endl;
}

// receives a filename and a pointer to a map
// when function returns, the map will be populated with
// the probability of each bigram in the file
void calc_bigrams(const char* fn, map<pair<string, string>, float>& bigram_map) {
	ifstream fin(fn);

	string word="", prevword;

    map<string, int> wordCount;
    map<pair<string,string>, int> pairCount;
    //Record frequency of each word and pair. For accuracy this function erases nonletter characters from each word
    while(fin>>word){
        std::string::iterator it;

        //Iteratres through the word to see if each letter is an alpha char key and is not equal to '
        //We don't want to erase ' because some words might contain them i.e "you're"
        for(int i = 0;i<word.length(); i++){
            if(!isalpha(word[i]) && ((int)word[i] != 39))
                word.erase(i);
        }

        if(prevword == "")
            prevword = word;

        else{
            pairCount[pair<string,string>(prevword,word)]++;
            prevword = word;
        }

        wordCount[word]++;
    }

    //Calculation of bigram probability for each pair
    map<pair<string,string>, int>::iterator it;
    for(it = pairCount.begin();it != pairCount.end(); it++){
        bigram_map[pair<string,string>(it->first.first, it->first.second)] =
            (float) (pairCount[pair<string,string>(it->first.first, it->first.second)]) /
                (float) (wordCount[it->first.first]);
    }

}
