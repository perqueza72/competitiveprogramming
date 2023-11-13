#include <bits/stdc++.h>

using namespace std;

void remove(map<int, int> &leMape, const int &val){
    leMape[val]--;
    if(leMape[val] == 0) leMape.erase(val);
}

int main(){
    int n, x, aux;
    map<int, int> leMape;

    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> aux;

        if(leMape.count(aux)) leMape[aux]++;
        else leMape.insert({aux, 1});
    }

    int r = 0;
    while(leMape.size()){
        r++;

        int val = (--leMape.end())->first;
        remove(leMape, val);
        if(leMape.empty()) break;

        auto it = leMape.lower_bound((x-val));
        if(it == leMape.end()) it--;

        if((it->first + val) <= x){
            remove(leMape, it->first);
            if(leMape.empty()) break;
        }
    }

    cout << r << endl;


    return 0;
}