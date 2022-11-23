#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, avg, init = 0, sum = 0, getted = 0;
    long long r;
    cin >> n >> r >> avg;

    pair<long long,long long> p;
    vector<pair<long long, long long> > v;
    for(int i=0; i<n; i++){
        cin >> p.second >> p.first;
        init+= p.second;
        v.push_back(p);
    }

    long long needed = n*avg;
    sort(v.begin(), v.end());

    long long getAux;
    for(int i=0; i<n && needed != (getted+init); i++){

        getAux=(max(0ll, min(r-v[i].second, needed-getted-init)));
        getted+=getAux;
        sum+=v[i].first*getAux;
    }

    cout << sum;

    return 0;
}