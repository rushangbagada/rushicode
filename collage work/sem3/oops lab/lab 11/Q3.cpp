#include <bits/stdc++.h>
using namespace std;

int main(){
    string sentence, word;
    cout << "Enter sentence: ";
    getline(cin, sentence);
    cout << "Enter word to count: ";
    cin >> word;

    // transform to lowercase for case-insensitive match
    auto toLower = [](string s){ transform(s.begin(), s.end(), s.begin(), ::tolower); return s; };
    string s = toLower(sentence);
    string w = toLower(word);

    // tokenize by whitespace and punctuation
    int count = 0;
    string token;
    for(size_t i=0;i<s.size();){
        if(isalnum((unsigned char)s[i])){
            size_t j=i; while(j<s.size() && isalnum((unsigned char)s[j])) j++;
            token = s.substr(i, j-i);
            if(token==w) count++;
            i=j;
        } else i++;
    }

    cout << "The word '" << word << "' appears " << count << " times." << endl;
    return 0;
}
