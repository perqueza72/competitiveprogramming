#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, q;

    cin >> n;

    pair<int,int> p;
    vector<pair<int,int> > r;
    vector<pair<pair<int,int>, int> > v;
    for(int i=0; i<n; i++){
        cin >> p.second >> p.first;
        v.push_back({p, i+1});
    }
    sort(v.begin(), v.end());

    cin >> m;
    multiset<int> table;
    vector<vector<int> > aaaa(1010, vector<int>());

    for(int j=0; j<m; j++){
        cin >> q;
        table.insert(q);
        aaaa[q].push_back(j+1);
    }

    auto it = table.begin();
    int total = 0, index, selected_table;

    while(v.size() && table.size()){
        p = v.back().first;
        index = v.back().second;
        // cout << "p: " << p.first << endl;

        v.pop_back();

        it = lower_bound(table.begin(), table.end(), p.second);
        // cout << "it: " << *it << endl;
        if(it != table.end()){
            total+=p.first;

            selected_table = *it;
            // cout << "here" << endl;

            r.push_back({index, aaaa[selected_table].back()});
            aaaa[selected_table].pop_back();
            table.erase(it);
        }
    }

    cout << r.size() << " " << total << "\n";
    for(auto &p : r){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}