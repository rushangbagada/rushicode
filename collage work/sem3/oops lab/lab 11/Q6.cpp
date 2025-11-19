#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter paragraph (single line):\n";
    string s;
    getline(cin,s);

    // convert to lowercase
    string lower = s;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    // count words
    stringstream ss(lower);
    string token;
    int wordCount=0;
    while(ss>>token) wordCount++;
    cout<<"Word count: "<<wordCount<<"\n";

    // replace "c++" with "programming"
    string replaced = lower;
    size_t pos=0;
    while((pos = replaced.find("c++", pos))!=string::npos){
        replaced.replace(pos,3,"programming");
        pos += 11; // length of "programming"
    }
    cout<<"After replacement: "<<replaced<<"\n";

    // first and last occurrence of "class"
    size_t first = lower.find("class");
    size_t last = lower.rfind("class");
    if(first!=string::npos) cout<<"First 'class' at: "<<first<<"\n";
    else cout<<"'class' not found\n";
    if(last!=string::npos) cout<<"Last 'class' at: "<<last<<"\n";

    // reverse each word individually
    string out;
    string cur;
    for(size_t i=0;i<s.size();++i){
        if(isspace((unsigned char)s[i])|| ispunct((unsigned char)s[i])){
            reverse(cur.begin(), cur.end());
            out += cur;
            out += s[i];
            cur.clear();
        } else cur.push_back(s[i]);
    }
    if(!cur.empty()){ reverse(cur.begin(), cur.end()); out+=cur; }
    cout<<"Reversed words: "<<out<<"\n";
    return 0;
}
