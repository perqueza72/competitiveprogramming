#include <bits/stdc++.h>

using namespace std;


struct Dsu{
    vector<int> parents;

    int find(int n){
        if(n == parents[n]) return n;
        return parents[n] = find(parents[n]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;
        if(a < b)
            swap(a,b);
        parents[b] = a;
    }

    void resize(int n){
        parents.resize(n);
        for(int i=0; i<n; i++){
            parents[i] = i;
        }
    }
};

struct Edge{
    int origin;
    int destiny;
    int w;

    void operator()(int a, int b, int c){
        origin = a;
        destiny = b;
        w = c;
    }
};

struct Point{
    int x;
    int y;
};

bool operator<(const Edge &a, const Edge &b){
    return a.w < b.w;
}

Dsu dsu;




int dist(const Point &p, const Point &q){
    return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}

int mst(vector<Edge> &edges, int n, int k){
    dsu.resize(edges.size());
    Edge edge;

    int cost = 0, size = 0;
    for(int i=0; size<n-k && i<edges.size(); i++){
        edge = edges[i];
        if(dsu.find(edge.origin) == dsu.find(edge.destiny)) continue;

        size++;
        dsu.merge(edge.origin, edge.destiny);
        cost= max(edge.w, cost);
    }

    return cost;
}

int main(){

    int t;
    int k, m;

    vector<Edge> edges;
    Edge edge;

    vector<Point> points;
    Point p;
    
    cout.precision(2);
    cin >> t;
    while(t--){
        cin >> k >> m;
        edges.resize(0);
        points.resize(0);

        for(int i=0; i<m; i++){
            cin >> p.x >> p.y;
            points.push_back(p);
        }

        for(int i=0; i<m; i++){
            for(int j=1; j<m; j++){
                edge(i, j, dist(points[i], points[j]));
                edges.push_back(edge);
                edge.w = -edge.w;
            }
        }

        sort(edges.begin(), edges.end());
        int cost = mst(edges, m, k);

        cout << fixed << (sqrt(cost)) << "\n";
    }

    return 0;
}