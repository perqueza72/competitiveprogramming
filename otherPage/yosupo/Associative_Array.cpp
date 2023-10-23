#include <bits/stdc++.h>

using namespace std;

int main(){

    long long q, query, k , v, t;
    map<long long, long long> leMape;
    cin >> q;
    while(q--){
        cin >> t;
        if(t){
            cin >> k;
            if(!leMape.count(k)) cout << 0 << "\n";
            else cout << leMape[k] << "\n";
        }
        else{
            cin >> k >> v;
            if(leMape.count(k)) leMape[k] = v;
            else leMape.insert({k, v});
        }
    } 
    return 0;
}