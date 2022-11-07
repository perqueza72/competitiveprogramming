#include <bits/stdc++.h>

using namespace std;


struct Dsu{
  vector<int> nodes;

  Dsu(){}

  Dsu(int n){
    this->resize(n);
  }

  void resize(int n){
    nodes.resize(n+1);
    for(int i=0; i<=n; i++){
      nodes[i] = i;
    }
  }

  int parent(int a){
    if(nodes[a] == a) return a;
    return nodes[a] = parent(nodes[a]);
  }

  void join(int a, int b){
    a = parent(a);
    b = parent(b);

    if(a == b) return;
    nodes[a] = b;
  }

  // void operator()(int n){
  //   resize(n);
  // }
};

struct Edge{
  int origin;
  int destiny;
  int w;

  void operator()(int u, int v, int d){
    this->origin = u;
    this->destiny = v;
    this->w = d;
  }
};

bool operator<(const Edge &u, const Edge &v){
  return u.w < v.w;
}

struct Point{
  int x;
  int y;
};

int dist(const Point &p, const Point &q){
  return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}

int main(){
  int t, n, m, a, b;

   Dsu dsu;

  vector<Edge> edges;
  Edge edge;

  vector<Point> points;
  Point p;
  
  cin >> t;
  while(t--){

    cin >> n;
    dsu.resize(n);

    
    points.resize(0);
    for(int i=0; i<n; i++){
      cin >> p.x >> p.y;
      points.push_back(p);
    }

    cin >> m;
    for(int i=0; i<m; i++){
      cin >> a >> b;
      dsu.join(a,b);
    }


    edges.resize(0);
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        edge(i+1,j+1, dist(points[i], points[j]));
        edges.push_back(edge);
      }
    }
    sort(edges.begin(), edges.end());

    int connect = 0;
    for(Edge &edge : edges){
      if(dsu.parent(edge.origin) == dsu.parent(edge.destiny)) continue;

      connect++;
      dsu.join(edge.origin, edge.destiny);
      cout << edge.origin << " " << edge.destiny << "\n";
    }

    if(!connect) cout << "No new highways need\n";


    if(t) cout << "\n";
  }

  return 0;
}