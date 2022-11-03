#include <bits/stdc++.h>

using namespace std;


int n;
vector<int> z_function(string &s){
    string bear = "bear";
    vector<int> z(n, 0), bears(1, (int)1e9);
    int r, l;
    for(int i = l = r = 0; i<n; i++){
        if(i<r){
            z[i] = min(r-i, z[i-l]);
        }

        while(z[i] < bear.length() && s[i+z[i]] == bear[z[i]]){
            z[i]++;
        }

        if(z[i] == bear.size()){
            bears.push_back(i);
        }
        
        if(i+z[i] > r){
            r = i+z[i];
            l = i;
        }
    }

    return bears;
}

vector<int> bear;
void solve(){

    int sum = 0;
    for(int i=1; i<bear.size(); i++){
        sum+= n-
    }

    cout << sum << endl;
}

int main(){
    string s;
    cin >> s;
    n = s.size();
    bear = z_function(s);
    solve();
}