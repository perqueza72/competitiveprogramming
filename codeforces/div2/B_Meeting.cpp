#include <bits/stdc++.h>

using namespace std;

struct rad{
    int x;
    int y;
    int r;
};

int main(){

    rad r;
    deque<rad> rads;
    deque<pair<int, int> > q, q2;
    pair<int, int> p1, p2, aux;
    int n;

    cin >> p1.first >> p1.second >> aux.first >> aux.second;
    p2.first = max(p1.first, aux.first);
    p2.second = max(p1.second, aux.second);

    p1.first = min(p1.first, aux.first);
    p1.second = min(p1.second, aux.second);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> r.x >> r.y >> r.r;
        r.r = r.r*r.r;
        rads.push_back(r);
    }

    
    for(int i=p1.first; i<=p2.first; i++){
        q.push_back({i,p1.second});
        q.push_back({i,p2.second});
    }
    for(int j=p1.second+1; j<p2.second; j++){
        q.push_back({p1.first,j});
        q.push_back({p2.first,j});
    }

    pair<int, int> v;
    for(auto &rad : rads){
        while(q.size()){
            v = q.front();
            q.pop_front();
            
            if(rad.r < ((rad.x-v.first)*(rad.x-v.first) + (rad.y-v.second)*(rad.y-v.second)))
                q2.push_back(v);

        }
        q.swap(q2);

    }

    cout << q.size() << endl;
    // for(auto &a : q){
    //     cout << a.first << " " << a.second << endl;
    // }



    return 0;
}