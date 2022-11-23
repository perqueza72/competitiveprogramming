#include <bits/stdc++.h>

using namespace std;


void print(const int &i, const int & last){
    cout << i << " " << last;
}

int main(){

    int r, h, l, cont = 0, limit = 0, init = 1e5;
    vector<vector<int> > grid(1e4+10, vector<int>());
    while( cin >> l >> h >> r){
        grid[l].push_back(h);
        init = min(init, l);

        grid[r].push_back(-h);
        limit = max(r, limit);

    }

    for(int i=init; i<=limit; i++) sort(grid[i].begin(), grid[i].end());


    int last = 0, v, u;
    bool change, first = true;
    map<int, int> m;
    for(int i=init; i<=limit; i++){
        if(grid[i].empty()) continue;
        change = false;
        v = grid[i].back();
        if(v > 0){
            if(v > last){
                last = v;
                change = true;
            }
        }

        for(auto &v : grid[i]){
            if(v > 0){
                if(m.count(v)) m[v]++;
                else  m.insert({v, 1});

                if(v > last){
                    last = v;
                    change = true;
                }
            }
            else if(v < 0){
                if(m[abs(v)] == 1) m.erase(abs(v));
                else m[abs(v)]--;

                if(abs(v) == last){
                    if(m.size()){
                        u = (--m.end())->first;
                        if(u == last) continue;
                        last = u;
                        change = true;
                    }
                    else{
                        last = 0;
                        change = true;
                    }
                    
                }
            }
        }

        if(change){
            if(!first) cout << " ";
            first = false;
            print(i, last);
        }


        
    }

    if(last != 0) cout << " 0";
    cout << endl;

    return 0;
}