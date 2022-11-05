#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-10;
pair<int,int> gun;

double pendiente(pair<int,int> p){
    if(p.second-gun.second == 0) return 5000;
    return ((double)(p.first-gun.first)/((double)(p.second-gun.second)));
}

int main(){

    int n;
    pair<int,int> v, p;
    deque<pair<int,int> > q, q2;

    cin >> n >> gun.first >> gun.second;
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        q.push_back(p);
    }


    double m;
    int shots = 0;
    while(q.size()){
        v = q.front();
        q.pop_front();
        shots++;
        m = pendiente(v);
        while(q.size()){
            p = q.front();
            q.pop_front();
            if(abs(pendiente(p)-m) > EPSILON)
                q2.push_back(p);
            
        }

        q.swap(q2);
    }

    cout << shots << endl;
}