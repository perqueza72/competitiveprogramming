#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first > b.first;
}

int main(){

    int n, limit, sum=0;
    vector<pair<int, int> > p;
    vector<int> r;

    cin >> n >> limit;

    for(int i=1; i<=limit; i++){
        for(int j=0; j<32; j++){
            if(i&(1<<j)){
                p.push_back({(1<<j), i});
                break;
            }
        }
    }

    sort(p.begin(), p.end(), comp);
    for(auto &v : p){
        if(v.first+sum <= n){
            sum+=v.first;
            r.push_back(v.second);
        }
        if(sum == n) break;
    }

    if(sum == n){
        cout << r.size() << "\n";
        for(auto &v : r) cout << v << " ";
    }
    else cout << "-1";
    cout << endl;

    return 0;
}