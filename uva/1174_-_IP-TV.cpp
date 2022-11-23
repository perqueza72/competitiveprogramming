#include <bits/stdc++.h>

using namespace std;


struct Dsu{
    vector<int> parent;


    void resize(const int &n){
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    Dsu(){

    }

    Dsu(const int &n){
        resize(n);
    }

    void operator()(const int &n){
        resize(n);
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(a < b)
            swap(a, b);
        
        parent[b] = a;
    }
};

struct Edge{
    int origin;
    int destiny;
    int w;

    void operator()(const int &origin, const int &destiny, const int &w){
        this->origin = origin;
        this->destiny = destiny;
        this->w = w;
    }
};

bool operator<(const Edge &e, const Edge &r){
    return e.w < r.w;
}


vector<Edge> edges;
Dsu dsu;
int n;

int kruskal(){

    Edge e;
    int k = 0, price = 0;
    for(int i=0; i<edges.size() && k < n-1; i++){
        e = edges[i];
        if(dsu.find(e.origin) == dsu.find(e.destiny)) continue;

        k++;
        price+= e.w;
        dsu.merge(e.origin, e.destiny);
    }

    return price;
}

int main(){

    int t, m, w;
    map<string, int> cities;
    string origin, f;

    Edge e;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> m;

        dsu.resize(n);
        edges.resize(0);
        cities = map<string, int>();

        for(int i=0; i<m; i++){
            cin >> origin >> f >> w;
            cities.insert({origin, cities.size()});
            cities.insert({f, cities.size()});

            e(cities[origin], cities[f], w);
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end());

        cout << kruskal() << "\n";
        if(t) cout << "\n"; 
    }

    return 0;
}