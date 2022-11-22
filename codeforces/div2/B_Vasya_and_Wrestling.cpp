#include <bits/stdc++.h>

using namespace std;


bool operator!=(const vector<int> &u, const vector<int> &v){
    if(u.size() != v.size()) return true;
    for(int i=0; i<u.size(); i++){
        if(u[i] != v[i]) return true;
    }

    return false;
}

bool operator<(const vector<int> &u, const vector<int> &v){
    for(int i=0; i<min(u.size(), v.size()); i++){
        if(u[i] < v[i]) return true;
    }
    if(u.size() < v.size()) return true;
    return false;
}

int main(){

    int n;
    bool last;
    long long a, sum = 0;

    cin >> n;
    vector<int> w, s;
    while(n--){
        cin >> a;
        if(a < 0){
            w.push_back(abs(a));
            last = 0;
        }
        else{
            s.push_back(a);
            last = 1;
        }

        sum+=a;

    }

    if(sum == 0){
        if(s != w) cout << (s > w ? "first" : "second") << endl;
        else cout << (last ? "first" :  "second") << endl;
    }else{
        cout << (sum > 0 ? "first" : "second") << endl; 
    }

    return 0;
}