#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int s_size, string s){
    s_size++;
    int r, l;
    vector<int> z((int) s.size(), 0);
    for(int  i = l = r = 1; i<s.size(); i++){
        if(i <= r){
            z[i] = min(r-i, z[i-l]);
        }

        while(i+z[i] < s.size() && s[z[i]+i] == s[z[i]])
            z[i]++;

        
        if(z[i]+i > r){
            r = z[i]+ i;
            l = i;
        }
    }

    return z;
}

int main(){
    string s, w;
    while(cin >> s){
        w = "";
        for(int i=s.size()-1; i>= 0; i--){
            w.push_back(s[i]);
        }
        w += "&" + s;

        vector<int> z = solve(s.size(), w);
        for(int i=s.size()+1; i<w.size(); i++){
            if(z[i]+i-s.size()-1 == s.size()){
                cout << s << (w.substr(z[i], i-s.size()-1)) << "\n";
                break;
            }
        }
    }

    return 0;
}