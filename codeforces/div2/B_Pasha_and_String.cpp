#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    vector<int> v((int)s.size());

    int n, q;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> q;
        q--;
        v[q]++;
        v[s.size()-q-1]--;
    }

    int swaps = 0;
    for(int i=0; i<s.size(); i++){
        if(v[i] > 0) swaps+= v[i];
        // cout << "v_i: " << v[i] << endl;
        cout << ((swaps & 1) ? s[s.size()-1-i] : s[i]);
        
        if(v[i] < 0) swaps+= v[i];
    }
    

    return 0;
}