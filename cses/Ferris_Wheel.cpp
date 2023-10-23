#include <bits/stdc++.h>

using namespace std;



map<int, int> leMap;

int x, n;

int fit(){

    int gondola = 0;
    while(!leMap.empty()){
        auto it = leMap.rbegin();
        int v = it->first;
        // cout << "v: "<< v<<endl;

        leMap[v]--;
        if(leMap[v] == 0) leMap.erase(v);
        gondola++;
        if(leMap.empty()) break;

        auto itInv = leMap.lower_bound(x-v);

        // cout << itInv-> first << " " << itInv->second << "\n";

        if(itInv == leMap.end()) --itInv;
        else if(itInv->first > (x-v) && leMap.begin() != itInv) --itInv;
        else if(itInv->first > (x-v) && leMap.begin() == itInv) continue;

        leMap[itInv->first]--;
        // cout << itInv-> first << " " << itInv->second << "\n";
        if(leMap[itInv->first] == 0) leMap.erase(itInv->first);
        
    }

    return gondola;
}


int main(){

    int aux;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> aux;
        if(leMap.count(aux)) leMap[aux]++;
        else leMap.insert({aux, 1});
    }

    // for(auto &a : leMap){
    //     cout << a.first << " " << a.second << endl;
    // }
    cout << fit() << endl;

    return 0;
}