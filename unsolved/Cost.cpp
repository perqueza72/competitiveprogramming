#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int origin;
  int destiny;
  int w;
};

bool operator<(const Edge &u, const Edge &v){
  return u.w < v.w;
}

struct Dsu{

  vector<int> nodes;

  Dsu(const int &n){
    nodes.resize(n+1);
  }


  void make_set(const int v){
    nodes[v] = v;
  }

  int parent(int v){
    if(v == nodes[v]) return v;
    return nodes[v] = parent(nodes[v]);
  }

  void join(int u, int v){
    u = parent(u);
    v = parent(v);

    if(u == v) return;
    nodes[v] = u;
  }
};

int main(){

  int n, m;
  Edge e;
  vector<Edge> edges;
  cin >> n >> m;

  Dsu *dsu = new Dsu(n);
  for(int i=0; i<m; i++){
    cin >> e.origin >> e.destiny >> e.w;

    dsu->make_set(e.origin);
    dsu->make_set(e.destiny);

    e.w = -e.w;
    edges.push_back(e);
  }

  sort(edges.begin(), edges.end());

  int cost = 0;
  for(Edge &edge : edges){
    if(dsu->parent(edge.origin) == dsu->parent(edge.destiny)) continue;
    cost+= edge.w;
    dsu->join(edge.origin, edge.destiny);
  }

  cout << (-cost) << endl;

  return 0;
}