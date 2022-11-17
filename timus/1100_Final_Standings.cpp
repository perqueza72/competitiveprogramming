#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int,int> &p1, const pair<int,int> &p2){
    return p1.second > p2.second;
}

int main(){
    int n;
    vector<pair<int, int> > v;
    pair<int, int> p;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    stable_sort(v.begin(), v.end(), comp);
    for(auto &u : v){
        cout << u.first << " " << u.second << "\n";
    }

    return 0;
}