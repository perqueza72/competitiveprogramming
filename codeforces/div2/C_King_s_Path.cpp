#include <bits/stdc++.h>

using namespace std;

int main(){

    pair<int,int> origin, destiny, newOne;
    set<pair<int, int> > allow;

    cin >> origin.first >> origin.second >> destiny.first >> destiny.second;

    int n, a, b, r;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> r >> a >> b;
        for(int j=a; j<=b; j++){
            allow.insert({r,j});
        }
    }
    allow.insert(destiny);

    deque<pair<int,int> > q, qAux;
    q.push_back(origin);

    int cont = 0;

    // cout << q.size() << endl;
    while(q.size()){
        while(q.size()){
            pair<int,int> &v = q.front();
            q.pop_front();

            // cout << v.first << " " <<v.second << endl;
            if(v == destiny){
                cout << cont << endl; 
                return 0;
            }

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i == 0 && j == 0) continue;

                    newOne = {v.first+i, v.second+j};
                    if(allow.count(newOne)){
                        qAux.push_back(newOne);
                        allow.erase(newOne);
                    }
                }
            }
        }

        q.swap(qAux);
        cont++;
    }

    cout << -1 << endl;

    return 0;
}