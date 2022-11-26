#include <bits/stdc++.h>

using namespace std;

int main(){

    map<pair<int, int>, int > exist;

    map<int, int> appearX, appearY;
    set<int> x, y;

    int n;
    pair<int, int> p;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p.first >> p.second;
        
        if(exist.count(p)) exist[p]++;
        else exist.insert({p,1});

        if(appearX.count(p.first)) appearX[p.first]++;
        else appearX.insert({p.first, 1});

        if(appearY.count(p.second)) appearY[p.second]++;
        else appearY.insert({p.second, 1});
    }

    long long sum = 0, aux;
    for(auto &item : exist){
        pair<int, int> p = item.first;

        aux = 0;
        if(!x.count(p.first)){
            x.insert(p.first);

            long long a = appearX[p.first];
            aux+= (a*(a-1))/2;
        }

        if(!y.count(p.second)){
            y.insert(p.second);

            long long a = appearY[p.second];
            aux+= (a*(a-1))/2;
        }

        long long a = (exist.find(p)->second);
        aux-= (a*(a-1))/2;

        // if(x.count(p.first) && y.count(p.second)) aux--;
        
        // cout << "Aux " << aux << " con pair " << p.first << " " << p.second << endl;
        // printf("Aux %d con pair {%d,%d}\n", aux, p.first, p.second);
        sum+= aux;
    }

    cout << sum << endl;

    return 0;
}