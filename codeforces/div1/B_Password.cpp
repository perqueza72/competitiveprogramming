#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    const int tam = (int)1e6+10; 
    string s, w;
    cin >> s;
    int it[tam] = {0};

    w = s + "&" + s;
    vector<int> z = z_function(w);
    for(int i=s.size()+2; i<w.size(); i++){
        it[z[i]]++;
    }
    for(int i=tam-2; i>=0; i--){
        it[i] += it[i+1];
    }

    int maxi = 0;

    for(int i=s.size(); i<w.size(); i++){
        if(z[i]+i == w.size() && it[z[i]] >= 2)
            maxi = max(maxi, z[i]);
    }
    
     cout << (maxi > 0 ? s.substr(0, maxi) : "Just a legend") << endl;




    return 0;
}