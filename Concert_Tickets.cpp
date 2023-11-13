#include <bits/stdc++.h>

using namespace std;

int main(){

    map<int, int> leMape;
    int n, m, query, aux;
    cin >> n >> m;
    for(int i=0; i<n;i++){
        cin >> aux;
        leMape.insert({aux, 1});
    }

    for(int i=0; i<m; i++){
        cin >> query;

        auto it = leMape.lower_bound(query);
        it--;
        if(it == leMape.end()){
            cout << -1 << "\n";
            continue;
        }

        cout << (it->first) << "\n";
        if(it->second == 1) leMape.erase(it);
        else it->second-=1;
    }

    return 0;
}