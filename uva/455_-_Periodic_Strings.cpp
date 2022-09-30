#include <bits/stdc++.h>

using namespace std;


vector<int> z_function(string s){
    vector<int> z((int)s.size()), aux;
    z[0] = 0;
    int r, l, n = s.size()/2;
    for(int i, r = l = i = 1; i<s.size(); i++){
        if(i <= r){
            z[i] = min(r-i, z[i-l]);
        }

        while(i+z[i] < s.size() && s[z[i]] == s[z[i]+i])
            z[i]++;
        
        if(i+z[i] > r){
            r = i+z[i];
            l = i;
        }
    }
    for(int i=n+1; i<s.size(); i++){
        if(z[i] > 0 && n/z[i]*z[i] == n){
            aux.push_back(z[i]);
        }
    }
    z.swap(aux);
    sort(z.begin(), z.end());
    unique(z.begin(), z.end());

    return z;
}

int main(){

    int n, veces, mini;
    string s, w, sub, aux;
    cin >> n;
    while(n--){
        cin >> s;
        sub = s;
        w = s + "&" + s;
        auto data = z_function(w);


        mini = 200;
        for(int i=data.size()-1; i>=0; i--){
            while(sub.size() > data[i])
                sub.pop_back();
            veces = s.size()/data[i];
            aux = "";
            for(int j=0; j<veces; j++){
                aux+= sub;
            }
            if(aux == s) mini = data[i];
        }

        cout << mini << "\n";
        if(n) cout << "\n";

    }
}