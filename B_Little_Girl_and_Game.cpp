#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    int r[26] = {0};
    cin >> s;
    for(auto &c : s) r[c-'a']++;
    
    int cont = -1;
    for(int i=0; i<26; i++) if(r[i] & 1) cont++;

    int select = max(0, cont);

    cout << ((select & 1 ) ? "Second" : "First" ) << endl;

    return 0;
}